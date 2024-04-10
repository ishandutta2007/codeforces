#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const ll pr1 = 1000000000100011LL;
const ll pr2 = 1011001110001111LL;

const int N = 1000010;
string s[N];
int n;
char ans[N];
int sze;

ll pow256[2][N];

int main()
{
	pow256[0][0] = 1;
	Loop(i, 1, N)
		pow256[0][i] = pow256[0][i - 1] * 256LL % pr1;
	pow256[1][0] = 1;
	Loop(i, 1, N)
		pow256[1][i] = pow256[1][i - 1] * 256LL % pr2;
	FAST;
	cin >> n >> ans;
	Loop(i, 1, n)
		cin >> s[i];
	sze = strlen(ans);
	Loop(k, 1, n)
	{
		ll m11 = 0, m12 = 0;
		ll m21 = 0, m22 = 0;
		int bound = min(sze, (int)s[k].size());
		int p = 0;
		Loop(i, 0, bound)
		{
			m11 = (m11 + pow256[0][i] * ans[sze - 1 - i]) % pr1;
			m12 = (m12 * 256LL + s[k][i]) % pr1;
			m21 = (m21 + pow256[1][i] * ans[sze - 1 - i]) % pr2;
			m22 = (m22 * 256LL + s[k][i]) % pr2;
			if (m11 == m12 && m21 == m22)
				p = i + 1;
		}
		Loop(i, p, s[k].size())
			ans[sze++] = s[k][i];
	}
	ans[sze] = '\0';
	cout << ans;
}