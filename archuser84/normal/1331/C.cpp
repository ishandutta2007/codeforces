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

const int f[] = { 4,1,3,2,0,5 };

int main()
{
	int x;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		ans += Bit(x, i) << f[i];
	}
	cout << ans << '\n';
}