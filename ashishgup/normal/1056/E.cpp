#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;
const int P1=31;
const int MOD1=1e9+7;

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

int n, m;
string s, t;
vector<int> z, o;
Hashs h;

bool check(int l0, int l1, int h0, int h1)
{
	if(h0==h1)
		return 0;
	int idx=0;
	bool check=1;
	for(auto &it:s)
	{
		if(it=='0')
		{
			int cur=h.get_hash(idx, idx+l0-1);
			check&=(cur==h0);
			idx+=l0;
		}
		else
		{
			int cur=h.get_hash(idx, idx+l1-1);
			check&=(cur==h1);
			idx+=l1;
		}
		if(!check)
			break;
	}
	return check;
}

int32_t main()
{
	IOS;
	cin>>s>>t;	
	n=s.size();
	m=t.size();
	h = Hashs(t, P1, MOD1);
	int x=0, y=0; //numbers of 0s and 1s
	int idx=0;
	for(auto &it:s)
	{
		if(it=='0')
		{
			z.push_back(idx);
			x++;
		}
		else
		{
			o.push_back(idx);
			y++;
		}
		idx++;
	}
	int ans=0;
	int sqt=sqrt(m);
	if(x>=sqt)
	{
		for(int i=1;;i++)
		{
			if(i*x>=m)
				break;
			if((m-i*x)%y)
				continue;
			int j=(m-i*x)/y;
			int h0=-1, h1=-1;
			int idx=z[0];
			idx*=j;
			h0=h.get_hash(idx, idx+i-1);
			idx=o[0];
			idx*=i;
			h1=h.get_hash(idx, idx+j-1);
			ans+=check(i, j, h0, h1);
		}
	}	
	else if(y>=sqt)
	{
		for(int j=1;;j++)
		{
			if(j*y>=m)
				break;
			if((m-j*y)%x)
				continue;
			int i=(m-j*y)/x;
			int h0=-1, h1=-1;
			int idx=z[0];
			idx*=j;
			h0=h.get_hash(idx, idx+i-1);
			idx=o[0];
			idx*=i;
			h1=h.get_hash(idx, idx+j-1);
			ans+=check(i, j, h0, h1);
		}
	}
	else
	{
		for(int i=1;;i++)
		{
			if(i*x>=m)
				break;
			if((m-i*x)%y)
				continue;
			int j=(m-i*x)/y;
			int h0=-1, h1=-1;
			int idx=z[0];
			idx*=j;
			h0=h.get_hash(idx, idx+i-1);
			idx=o[0];
			idx*=i;
			h1=h.get_hash(idx, idx+j-1);
			ans+=check(i, j, h0, h1);
		}
	}
	cout<<ans;
	return 0;
}