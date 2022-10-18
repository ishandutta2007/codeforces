#include <bits/stdc++.h>
#pragma pack(1)

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	long long sum=0;
	for(int i=0;i<n;i++)
		sum+=(long long)a[i]*(i+2-(i==n-1));
	cout<<sum<<endl;
	
}