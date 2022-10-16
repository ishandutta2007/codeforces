#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a1,a2,k1,k2,n;
int main()
{
	cin>>a1>>a2>>k1>>k2>>n;
	cout<<max(0,n-a1*(k1-1)-a2*(k2-1))<<" ";
	if(k1<k2){
		if(n<=k1*a1)cout<<n/k1;
		else cout<<(n-k1*a1)/k2+a1;
	}
	else{
		if(n<=k2*a2)cout<<n/k2;
		else cout<<(n-k2*a2)/k1+a2;
	}
	return 0;
}