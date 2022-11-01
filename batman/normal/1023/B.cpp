#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)501*1000)

ll n,k;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	cout<<max(0ll,min(n,k-1)-(k/2+1)+1);
	return 0;
}