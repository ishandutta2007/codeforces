#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n;
	for(cin>>T;T--;){
		cin>>n;
		vector<int>v;
		int x;
		while(n--)cin>>x,v.push_back(x);
		sort(begin(v),end(v));
		cout<<v[v.size()-1]+v[v.size()-2]<<'\n';
	}
}