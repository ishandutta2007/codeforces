#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, ans=0;
int a[N];
string s;
vector<int> m[256];
char ch;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>s;
	ch=s[0];
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]==ch)
		{
			m[s[i-1]].push_back(a[i]);
			continue;
		}
		else
		{
			sort(m[ch].rbegin(), m[ch].rend());
			int sz=m[ch].size();
			for(int j=0;j<min(k, sz);j++)
				ans+=m[ch][j];
			m[ch].clear();
			m[s[i-1]].push_back(a[i]);
			ch=s[i-1];
		}
	}
	sort(m[ch].rbegin(), m[ch].rend());
	int sz=m[ch].size();
	for(int i=0;i<min(k, sz);i++)
		ans+=m[ch][i];
	m[ch].clear();
	cout<<ans;
	return 0;
}