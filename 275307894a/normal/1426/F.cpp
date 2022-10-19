#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,z,tot;
long long po[200039],ans,now,nowp,lasc[200039],qa[200039],las[200039],q[200039];
char s[200039],_s;
int main() {
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		_s=getchar();
		while(_s!='a'&&_s!='b'&&_s!='c'&&_s!='?') _s=getchar();
		s[i]=_s;
	}
	for(i=1;i<=n;i++)q[i]=q[i-1]+(s[i]=='?'?1:0),qa[i]=qa[i-1]+(s[i]=='a'?1:0);
	for(i=n;i>=1;i--)las[i]=las[i+1]+(s[i]=='?'?1:0),lasc[i]=lasc[i+1]+(s[i]=='c'?1:0);
	for(i=1;i<=n;i++)if(s[i]=='?') tot++;
	po[3]=1;
	for(i=4;i<=tot+3;i++) po[i]=po[i-1]*3%mod;
	for(i=2;i<=n;i++){
		if(s[i]=='b')ans=(ans+qa[i-1]*lasc[i+1]%mod*po[tot+3]%mod+q[i-1]*lasc[i+1]%mod*po[tot+2]%mod+qa[i-1]*las[i+1]%mod*po[tot+2]%mod+q[i-1]*las[i+1]%mod*po[tot+1]%mod)%mod;
		if(s[i]=='?')ans=(ans+qa[i-1]*lasc[i+1]%mod*po[tot+2]%mod+q[i-1]*lasc[i+1]%mod*po[tot+1]%mod+qa[i-1]*las[i+1]%mod*po[tot+1]%mod+q[i-1]*las[i+1]%mod*po[tot]%mod)%mod;
	}
	printf("%lld\n",ans);
}