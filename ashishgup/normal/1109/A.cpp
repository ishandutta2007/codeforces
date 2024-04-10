#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3e5+5;

int n, cur=0;
int a[N], pref[N];
int cnt[2][1LL<<20];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cnt[0][0]++;
	for(int i=1;i<=n;i++)
	{
		pref[i]=pref[i-1] ^ a[i];
		cur+=cnt[i%2][pref[i]];
		cnt[i%2][pref[i]]++;
	}
	cout<<cur;
	return 0;
}