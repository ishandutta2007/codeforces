#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,x,k;
	for(cin>>T;T--;){
		cin>>n>>x;
		set<int>s;
		int ans=0;
		for(i=1;i<=n;++i){
			cin>>j;
			s.insert(j);
			if(*s.rbegin()-*s.begin()>2*x)++ans,s={j};
		}
		cout<<ans<<'\n';
	}
}