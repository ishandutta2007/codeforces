#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[105],ans=1e9;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<n;i++){
		int cnt=0;
		for(int j=2;j<=n;j++)
			if(i!=j)cnt=max(cnt,abs(a[j]-a[j-1-(i==j-1)]));
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}