#include<bits/stdc++.h>
using namespace std;
long long n,a,k;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		k+=(a-1)*(i-1)+a;
	}
	cout<<k;
	return 0;
}