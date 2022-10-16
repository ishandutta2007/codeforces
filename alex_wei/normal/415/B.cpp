#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,x;
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		ll m=x*a/b*b;
		cout<<x-(m%a>0)-m/a<<" ";
	}
    return 0;
}