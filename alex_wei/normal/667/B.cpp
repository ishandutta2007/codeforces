#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,l[N],s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	sort(l+1,l+n+1);
	for(int i=1;i<n;i++)s+=l[i];
	cout<<max(0ll,l[n]+1-s);
	return 0;
}