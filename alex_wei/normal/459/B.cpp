#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <ll,ll> c;
ll l=1e9,r,n,k;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>k,c[k]++,l=min(l,k),r=max(r,k);
	cout<<r-l<<" "<<(l==r?c[r]*(c[l]-1)/2:c[r]*c[l]);
    return 0;
}