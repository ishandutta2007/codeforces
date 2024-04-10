#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

ll x,y,a,b,t; 
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y>>a>>b;
		ll div=y-x,s=a+b;
		if(div%s)puts("-1");
		else cout<<div/s<<endl;
	}
    return 0;
}