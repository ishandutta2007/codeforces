#include<bits/stdc++.h>
using namespace std;
const int N=79;
int a[N];
struct F{
	int x,y;
	bool operator<(F a){
		return x*a.y<a.x*y;
	}
};
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,ans,k,l;
	for(cin>>T;T--;){
		cin>>n;ans=n;
		for(i=1;i<=n;++i)cin>>a[i];
		if(n==1)goto gg;
		for(i=1;i<=n;++i){
			deque<F>v; 
			for(j=1;j<=n;++j)if(i^j){
				if(i-j>0)v.push_back({a[i]-a[j],i-j});
				else v.push_back({a[j]-a[i],j-i});
			}
			sort(v.begin(),v.end());
			F now=v.front();v.pop_front();
			int cnt=1,mx=1;
			for(auto o:v){
				if(o.x*now.y==now.x*o.y){
					++cnt;
					mx=max(mx,cnt);
				}
				else cnt=1,now=o;
			}
			ans=min(ans,n-mx);
		}gg:;
		cout<<ans-1<<'\n';
	}
	return 0;
}