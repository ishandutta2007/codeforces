#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,a,b;
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(__gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
    return 0;
}