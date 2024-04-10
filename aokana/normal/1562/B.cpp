#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	vis[1]=true;
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
		}
	}
}
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	sieve(1000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		for(ri i=1;i<=n;++i)a[i]=s[i]^48;
		bool flag=false;
		for(ri i=1;i<=n;++i)
			if(vis[a[i]]){
				puts("1");
				printf("%d\n",a[i]);
				flag=true;
				break;
			}
		if(flag)continue;
		for(ri i=1;i<n;++i){
			for(ri j=i+1;j<=n;++j)
				if(vis[a[i]*10+a[j]]){
					puts("2");
					printf("%d%d\n",a[i],a[j]);
					flag=true;
					break;
				}
			if(flag)break;
		}
		if(flag)continue;
		for(ri i=1;i<n;++i){
			for(ri j=i+1;j<n;++j){
				for(ri k=j+1;k<=n;++k)
					if(vis[a[i]*100+a[j]*10+a[k]]){
						puts("3");
						printf("%d%d%d\n",a[i],a[j],a[k]);
						flag=true;
						break;
					}
				if(flag)break;
			}
			if(flag)break;
		}
	}
	return 0;
}