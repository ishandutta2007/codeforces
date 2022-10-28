#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int vis[N];
pair<int, int> a[N];
string s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	cin>>s;
	int left=1;
	stack<int> st;
	for(int i=0;i<2*n;i++)
	{
		if(s[i]=='0')
		{
			cout<<a[left].second<<" ";
			st.push(a[left].second);
			left++;
		}
		else
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	return 0;
}