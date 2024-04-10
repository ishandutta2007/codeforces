#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c,sum;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c>>sum;
		ll j=sum/c,rem=sum%c;
		cout<<(c-rem)*j*j+rem*(j+1)*(j+1)<<endl;
	}
    return 0;
}