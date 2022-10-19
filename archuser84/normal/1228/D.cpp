#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100000;

vector<int> A[N];
vector<int> v1;
vector<int> v2;
vector<int> v3;
ll s1, s2, s3;
int tag[N] = {};
int n, m;

bool adj(int u, int v)
{
	int l = 0, r = A[u].size() - 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (A[u][mid] == v)
			return true;
		else if (A[u][mid] < v)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return A[u][l] == v;
}

bool check()
{
	Loop(i, 0, n)
	{
		switch(tag[i])
		{
		case 0: return 0;
		case 1: if (A[i].size() != s2 + s3)return 0; for (int x : A[i])if (tag[x] == 1)return 0; break;
		case 2: if (A[i].size() != s1 + s3)return 0; for (int x : A[i])if (tag[x] == 2)return 0; break;
		case 3: if (A[i].size() != s1 + s2)return 0; for (int x : A[i])if (tag[x] == 3)return 0; break;
		}
	}
	return 1;
}

void Solve()
{
	v1.push_back(0); tag[0] = 1;
	if (A[0].size() < 2)
	{
		cout << "-1";
		return;
	}
	sort(all(A[0]));
	Loop(i, 1, n)
	{
		if (!adj(0, i))
		{
			v1.push_back(i);
			tag[i] = 1;
		}
	}
	int u = A[0][0];
	v2.push_back(u); tag[u] = 2;
	if (A[u].size() < 2)
	{
		cout << "-1";
		return;
	}
	sort(all(A[u]));
	Loop(i, 0, n)
	{
		if (tag[i] || i == u)
			continue;
		if (!adj(u, i))
		{
			v2.push_back(i);
			tag[i] = 2;
		}
		else
		{
			v3.push_back(i);
			tag[i] = 3;
		}
	}
	s1 = v1.size(); s2 = v2.size(); s3 = v3.size();
	if(m != s1*(s2+s3) + s2*s3 || s3 == 0)
	{
		cout << "-1";
		return;
	}
	if(!check())
	{
		cout << "-1";
		return;
	}
	else
	{
		Loop(i, 0, n)
		{
			cout << tag[i] << ' ';
		}
	}
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Solve();
}