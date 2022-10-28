#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]++;
		ans+=(a[i]==i);
	}
	int finans=ans;
	for(int i=1;i<=n;i++)
	{
		int idx1=a[i], idx2=a[a[i]];
		int initial=(idx1==a[idx1]) + (idx2==a[idx2]);
		swap(a[idx1], a[idx2]);
		int newval=(idx1==a[idx1]) + (idx2==a[idx2]);
		swap(a[idx1], a[idx2]);
		finans=max(finans, ans+newval-initial);
	}
	cout<<finans;
	return 0;
}