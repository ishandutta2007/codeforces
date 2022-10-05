#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		set<int>s;
		int ans=0,now=0;s.insert(0);
		for(i=1;i<=n;++i){
			cin>>j;
			if(!j){s.clear();s.insert(now);}else{
				++ans;
				now^=j;
				if(s.count(now)){
					--ans;
					s.clear();
				}s.insert(now);
			}
		}
		cout<<ans<<'\n';
	}
}