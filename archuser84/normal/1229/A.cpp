//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 7010;
ll a[N];
ll b[N];
ll sum = 0;
int n;

vector<int> T[N];
int Cnt;
int cnt[N];
bool out[N];

bool better(int w, int l)
{
	return (a[w] | a[l]) - a[l] > 0;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, n)
	{
		cin >> b[i];
		sum += b[i];
	}
	Loop(i, 0, n)
	{
		Loop(j, 0, n)
		{
			if (i == j)
				continue;
			if (better(i, j))
			{
				T[j].push_back(i);
				cnt[i]++;
			}
		}
	}
	Cnt = n;
	Loop(t, 0, n)
	{
		Loop(i, 0, n)
		{
			if (!out[i] && cnt[i] == Cnt-1)
			{
				Cnt--;
				sum -= b[i];
				out[i] = true;
				for (auto v : T[i])
					cnt[v]--;
			}
		}
	}
	if (Cnt >= 2)
		cout << sum;
	else
		cout << 0;
}