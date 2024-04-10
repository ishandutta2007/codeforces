#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int P1=1e9+7;
const int P2=1e9+9;
const int P3=1e7+7;
const int Q=26;

struct Hashs 
{
	vector<vector<int>> hashs;
	vector<int> pows;
	int P;
	Hashs(string &s, int P) : P(P) 
	{
		int n = s.size();
		pows.resize(n, 0);
		hashs.resize(n, vector <int> (Q, 0));
		hashs[0][s[0] - 'a']= 1;
		pows[0] = 1;
		for(int i=1;i<n;i++) 
		{
			for(int j=0;j<Q;j++) 
			{
				hashs[i][j] = hashs[i - 1][j] * 2 % P;
			}
			int c = s[i] - 'a';
			hashs[i][c] = (hashs[i][c] + 1) % P;
			pows[i] = pows[i - 1] * 2 % P;
		}
	}
	vector<int> get_hash(int l, int r) 
	{
		if(!l) 
		{
			return hashs[r];
		}
		vector<int> res(Q, 0);
		for (int i = 0; i < Q; i++) 
		{
			res[i] = (hashs[r][i] - hashs[l - 1][i] * pows[r - l + 1] % P + P) % P;
		}
		return res;
	}
};

int n, m;
string s;
vector<Hashs> data;

int32_t main()
{
	IOS;
	cin>>n>>m>>s;
	data.push_back(Hashs(s, P1));
	data.push_back(Hashs(s, P2));
	data.push_back(Hashs(s, P3));
	for(int i=0;i<m;i++)
	{
		int x, y, len;
		cin>>x>>y>>len;
		x--, y--;
		int check=1;
		for(int j=0;j<3;j++)
		{
			vector<int> a=data[j].get_hash(x, x+len-1);
			vector<int> b=data[j].get_hash(y, y+len-1);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			check&=(a==b);
		}
		if(check)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}