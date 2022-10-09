#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int maxa=0, maxb=0;
		for(int i=1;i<=m;++i){
			int a, b; 
			cin>>a>>b; 
			maxa=max(a, maxa);
			maxb=max(b, maxb);
		}
		if(maxa+maxb<=n){
			while(maxa--) cout<<"R", n--;
			while(maxb--) cout<<"W", n--;
			while(n--) cout<<"R";
			cout<<"\n";
		}
		else{
			cout<<"IMPOSSIBLE\n";
		}
	}
}