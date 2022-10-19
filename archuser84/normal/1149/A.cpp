#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
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

const int N = 200010;
int cnt[3] = {};
int n;

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	if (!cnt[1])
	{
		Loop(i, 0, cnt[2])
			cout << "2 ";
		return 0;
	}
	if (!cnt[2])
	{
		Loop(i, 0, cnt[1])
			cout << "1 ";
		return 0;
	}
	cout << "2 1 ";
	Loop(i, 1, cnt[2])
		cout << "2 ";
	Loop(i, 1, cnt[1])
		cout << "1 ";
}