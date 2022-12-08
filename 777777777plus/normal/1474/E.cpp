#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n,a[N],p[N];
vector<pair<int,int>> f;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		f.clear();
		ll ans=0;
		p[0]=0;
		p[++p[0]]=1;
		for(int i=n/2+1;i<=n;++i){
			p[++p[0]]=i,ans+=1ll*(i-1)*(i-1);
			if(i!=n)f.push_back({i,1});
		}
		for(int i=n/2;i>1;--i)p[++p[0]]=i,ans+=1ll*(n-i)*(n-i),f.push_back({i,n});
		f.push_back({1,n});
		printf("%lld\n",ans);
		for(int i=1;i<=n;++i)a[p[i]]=p[i+1];
		a[p[n]]=p[1];
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
		printf("%d\n",f.size());
		for(int i=0;i<f.size();++i){
			printf("%d %d\n",f[i].first,f[i].second);
		}
	}
}