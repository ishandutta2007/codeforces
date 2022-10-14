#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

#define fi(n) for(int i=0;i<n;i++)
#define fr(n) for(int i=n-1;i>=0;i--)
#define v(type) vector<type>
#define int long long
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerbits(x) __builtinctzll(x)
#define mod 1000000007
#define inf 1e18
#define W(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x

void aeh()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
bool match(string s1,string s2)
{
	int pos=0;
	int n=s2.size();
	fi(n)
		if(s1[pos]==s2[i])
			pos++;
	if(pos==s1.size())
		return true;
	return false;
}
int32_t main()
{
	aeh();
	string s;cin>>s;
	if(match("hello",s))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}