#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		vector<int>v;
		for(int i=1;i<=n;++i)cin>>j,v.push_back(j);
		if(is_sorted(begin(v),end(v)))cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}