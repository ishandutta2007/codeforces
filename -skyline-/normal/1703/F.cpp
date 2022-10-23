#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,t[200005],a[200005];
void add(int x){while(x<=n)++t[x],x+=(x&-x);}
int sum(int x){int s=0;while(x)s+=t[x],x-=(x&-x);return s;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ll ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			t[i]=0;
		}
		for(int i=1;i<=n;++i){
			if(a[i]>=i) continue;
			ans+=sum(a[i]);
			add(i+1);
		}
		printf("%I64d\n",ans);
	}
    return 0;
}