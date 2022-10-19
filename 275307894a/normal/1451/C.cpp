#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[139],t,b[139],ans,tot,flag;
char s;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
		scanf("%d",&n);ans=tot=0;scanf("%d",&k);
		for(i=1;i<=n;i++){
			s=getchar();
			while(s<'a'||s>'z') s=getchar();
			a[s-'a'+1]++;
		}
		for(i=1;i<=n;i++){
			s=getchar();
			while(s<'a'||s>'z') s=getchar();
			b[s-'a'+1]++;
		}
		flag=0;
		for(i=1;i<=26;i++){
			if(a[i]<b[i]){flag=1;break;}
			if((a[i]-b[i])%k!=0){flag=1;break;}
			a[i+1]+=a[i]-b[i];
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}