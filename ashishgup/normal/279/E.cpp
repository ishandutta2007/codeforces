#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s;
int cache[N][2];

int dp(int idx, int carry)
{
	if(idx==-1)
		return carry;
	int &ans=cache[idx][carry];
	if(ans!=-1)
		return ans;
	//Case 1: Adding what is required
	int cur=(s[idx]-'0'+carry)%2;
	int newcarry=(s[idx]-'0'+carry)/2;
	ans=dp(idx-1, newcarry)+cur;
	//Case 2: Assuming that 2^y is coming from a subtraction
	cur=(s[idx]-'0'+carry+1)%2;
	newcarry=(s[idx]-'0'+carry+1)/2;
	ans=min(ans, dp(idx-1, newcarry) + cur + 1);
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>s;
	n=s.size();
	int ans=dp(n-1, 0);
	cout<<ans;	
	return 0;
}