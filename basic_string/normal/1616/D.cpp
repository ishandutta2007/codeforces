#include<bits/stdc++.h>
using namespace std;
const int N=50009;
int a[N];
struct L{
	int x,y;
	bool operator<(L a)const{return y<a.y;}
};
vector<L>v;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,ans,k,l;
	for(cin>>T;T--;){
		cin>>n;v.clear();
		for(i=1;i<=n;++i)cin>>a[i];
		cin>>j;
		for(i=1;i<=n;++i)a[i]-=j;
		for(i=1;i<=n;++i){
			if(i+1<=n&&a[i]+a[i+1]<0)v.push_back({i,i+1});
			if(i+2<=n&&a[i]+a[i+1]+a[i+2]<0)
			v.push_back({i,i+2}); 
		}
		sort(begin(v),end(v));
		int las=-N,cnt=0;
		for(auto o:v){
			if(las>=o.x)continue;
			++cnt,las=o.y;
		}
		cout<<n-cnt<<'\n';
	}
	return 0;
}