#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;
 
	Hashs() {}
 
	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--) 
		{
			hashs[i]=(1LL * hashs[i+1] * P + s[i] - 'a' + 1) % MOD;
			pows[n-i]=(1LL * pows[n-i-1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n-1] * P)%MOD;
	}
	int get_hash(int l, int r) 
	{
		int ans=hashs[l] + MOD - (1LL*hashs[r+1]*pows[r-l+1])%MOD;
		ans%=MOD;
		return ans;
	}
};
 
int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
const int P1 = 27;
const int P2 = 31;
const int MOD = 1e9 + 7;
 
string a, b;
Hashs ha1, ha2;
Hashs hb1, hb2;
 
int32_t main()
{
	IOS;
	cin >> a >> b;
	ha1 = Hashs(a, P1, MOD);
	ha2 = Hashs(a, P2, MOD);
	hb1 = Hashs(b, P1, MOD);
	hb2 = Hashs(b, P2, MOD);
	pair<int, int> reqd = {hb1.get_hash(0, b.size() - 1), hb2.get_hash(0, b.size() - 1)};
	vector<int> v;
	for(int i = 0; i < a.size(); i++)
	{
		pair<int, int> have;
		int h = 0;
		if(a.size() - i - 1 > 0)
			h = ha1.get_hash(i + 1, a.size() - 1);
		int r = i;
		if(r > 0)
		{
			h *= pow(P1, r, MOD);
			h %= MOD;
			h += ha1.get_hash(0, i - 1);
			h %= MOD;
		}
		have.first = h;
		h = 0;
		if(a.size() - i - 1 > 0)
			h = ha2.get_hash(i + 1, a.size() - 1);
		r = i;
		if(r > 0)
		{
			h *= pow(P2, r, MOD);
			h %= MOD;
			h += ha2.get_hash(0, i - 1);
			h %= MOD;
		}
		have.second = h;
		if(have == reqd)
			v.push_back(i + 1);
	}
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it << " ";
	return 0;
}