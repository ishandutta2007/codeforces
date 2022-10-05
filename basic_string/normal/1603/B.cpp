#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,i,j,k;
	ll n,x,y;
	for(cin>>T;T--;){
		cin>>x>>y;
		if(x>y){cout<<x+y<<'\n';continue;}
		cout<<y-(y%x)/2<<'\n';
	}
	return 0;
}