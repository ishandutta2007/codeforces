#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=10005;

int n;
string s;
int cache[N][5][5];
set<string> st;

int dp(int idx, int x, int prv) //we can take length x substring starting at idx
{
	if(idx==n)
		return 1;
	if(idx+x>n)
		return 0;
	int &ans=cache[idx][x][prv];
	if(ans!=-1)
		return ans;
	ans=0;
	if(prv!=x)
		ans|=(dp(idx+x, 2, x) | dp(idx+x, 3, x));
	else
	{
		string s1=s.substr(idx, x);
		string s2=s.substr(idx-x, x);
		if(s1!=s2)
			ans|=(dp(idx+x, 2, x) | dp(idx+x, 3, x));
	}
	if(ans)
		st.insert(s.substr(idx, x));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s;
	n=s.size();
	for(int i=5;i<n;i++)
		dp(i, 2, 0), dp(i, 3, 0);
	cout<<st.size()<<endl;
	for(auto &it:st)
		cout<<it<<endl;
	return 0;
}