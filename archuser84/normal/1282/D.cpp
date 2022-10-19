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

const int N = 310;
bool a[N];
int n;
int bcnt;
int cnt;
char tmp[N];
char ans[N];

bool q(const char* s, int& n)
{
	printf("%s\n", s);
	fflush(stdout);
	scanf("%i", &n);
	return n;
}
bool q(int& n)
{
	printf("\n");
	fflush(stdout);
	scanf("%i", &n);
	return n;
}

int main()
{
	if (!q("b", n))
		return 0;
	Loop(i, 0, n)
		printf("a");
	if (!q(bcnt))
		return 0;
	cnt = bcnt;
	n++;
	Loop(i, 0, n)
	{
		tmp[i] = 'a';
		ans[i] = 'a';
	}
	tmp[n] = '\0';
	ans[n] = '\0';
	Loop(i, 0, n - 1)
	{
		tmp[i] = 'b';
		int x;
		if (!q(tmp, x))
			return 0;
		if (x == bcnt - 1)
		{
			ans[i] = 'b';
			cnt--;
		}
		tmp[i] = 'a';
	}
	if (cnt)
		ans[n - 1] = 'b';
	int x;
	q(ans, x);
}