#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,x,y; 
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		if(x-y<2)cout<<"NO\n";
		else cout<<"YES\n";
	}
    return 0;
}