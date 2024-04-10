#include<bits/stdc++.h>
using namespace std;
int n,k,ans; 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		ans+=r-l+1;
	}
	cout<<(ans%k?k-ans%k:0);
    return 0;
}