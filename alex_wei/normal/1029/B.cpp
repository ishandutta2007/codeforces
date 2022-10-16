#include<bits/stdc++.h>
using namespace std;
int n,a[200002],ans,cnt;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]*2>=a[i])cnt++;
		else ans=max(ans,cnt),cnt=1;
	}
	cout<<max(ans,cnt);
	return 0;
}