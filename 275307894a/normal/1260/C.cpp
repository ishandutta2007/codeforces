#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
long long t,n,m,k,x,y,z,ans,tot,pus,now;
inline void read(long long &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
	//freopen("color.in","r",stdin);
	//freopen("color.out","w",stdout);
	read(t);
	while(t--){
		read(n);read(m);read(k);
		ans=__gcd(n,m);tot=n*m/ans;pus=max(n,m);now=min(n,m);
		if(n==m) {
			if(k>1) printf("OBEY\n");
			else printf("REBEL\n");
			continue;
		}
		if(tot/n+tot/m-2<k) printf("OBEY\n");
		else{
			if((pus-ans-1)/now+1<k) printf("OBEY\n");
			else printf("REBEL\n");
		}
	}
	return 0;
}