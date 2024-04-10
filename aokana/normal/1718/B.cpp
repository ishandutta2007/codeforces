#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int a[maxn],m,n,t_case;
ll f[maxn],pre[maxn];
int main(){
	f[0]=f[1]=pre[0]=1,pre[1]=2;
	for(ri i=2;i<=60;++i){
		f[i]=f[i-2]+f[i-1];
		pre[i]=pre[i-1]+f[i];
	}
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ll sum=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),sum+=a[i];
		ri pos=-1;
		for(ri i=0;i<=60;++i)
			if(pre[i]==sum){
				pos=i;
				break;
			}
		typedef pair<int,int> pii;
		#define fi first
		#define se second
		priority_queue<int>q;
		for(ri i=1;i<=n;++i)q.push(a[i]);
		ri lst=0;
		while(~pos){
			if(q.empty()){
				puts("NO");
				goto skip;
			}
			ri x=q.top();q.pop();
			if(x<f[pos]){
				puts("NO");
				goto skip;
			}
			x-=f[pos--];
			if(lst)q.push(lst);
			lst=x;
		}
		puts(q.empty()?"YES":"NO");
		skip:;
	}
	return 0;
}