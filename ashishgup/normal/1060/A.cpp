#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=ch-'0';
		m[a[i]]++;
	}
	int ct8=m[8];
	int others=n-ct8;
	int make=min(ct8, others/10);
	ct8-=make;
	ans+=make;
	others-=make*10;
	int rem8=ct8;
	rem8+=others;
	make=min(ct8, rem8/11);
	ans+=make;
	cout<<ans;
	return 0;
}