#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n,a[N];
int fa[N];

int gf(int x){
	if(x>n)return n+1;
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int l=1;
		ll ans=0;
		fa[n+1]=n+1;
		for(int i=n;i>=1;--i)
		if(a[i]==1){
			fa[i]=gf(i+1);
		}
		else{
			fa[i]=i;
		}
		while(l<=n){
			if(l==n){
				ans+=a[l]-1;
				a[l]=1;
				break;
			}
			if(l+a[l]>n){
				ans+=l+a[l]-n;
				a[l]=n-l;
			}
			while(a[l]>1){
				int p=l;
				++ans;
				while(p<=n){
					a[p]--;
					if(a[p]==1)fa[p]=gf(p+1);
					p+=a[p]+1;
					p=gf(p);
				}
			}
			++l;
		}
		for(int i=1;i<=n;++i)if(a[i]>1){
			while(1)puts("GG");
		}
		printf("%lld\n",ans);
	}
}