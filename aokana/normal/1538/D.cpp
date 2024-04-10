#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],k,m,n,t_case;
ll tmp;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline void calc(int x){
	ri cnt=0,r=sqrt(x);
	for(ri i=2;i<=r;++i)
		while(x%i==0)
			++cnt,x/=i;
	if(x>1)++cnt;
	tmp+=cnt;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		ri g=gcd(n,m);
		if(k==1)puts(n!=m&&g==min(n,m)?"YES":"NO");
		else{
			tmp=0;
			calc(n),calc(m);
			puts(k<=tmp?"YES":"NO");
		}
	}
	return 0;
}