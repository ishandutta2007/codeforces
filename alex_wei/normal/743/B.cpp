#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll find(ll a,ll b){
	if(b==(1ll<<a-1))return a;
	return find(a-1,b>1ll<<a-1?b-(1ll<<a-1):b);
}
int main(){
	cin>>n>>k;
	cout<<find(n,k);
	return 0;
}