#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
vector<ll>v[65];
ll b[N],ans[N],x;
int n,i,j;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>b[i];
		for(j=60;j>=0;--j)if(b[i]>>j&1)break;
		v[j].push_back(b[i]);
	}
	for(i=1;i<=n;++i){
		for(j=0;j<60;++j)if(!(x>>j&1) && !v[j].empty())break;
		if(j==60)break;
		ans[i]=v[j].back();v[j].pop_back();
		x^=ans[i];
	}
	if(i<=n){
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	for(i=1;i<=n;++i)
                cout<<ans[i]<<' ';
}