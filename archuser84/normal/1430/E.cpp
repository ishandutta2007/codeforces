#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
char s[N], r[N];
int f[256];
int n;

class Fenwick
{
	int arr[N+1] = {};
public:
	void Add(int k, int v)
	{
		k++;
		while (k > 0)
		{
			arr[k] += v;
			k -= k & (-k);
		}
	}
	int Get(int k)
	{
		k++;
		int ans = 0;
		while (k <= n)
		{
			ans += arr[k];
			k += k & (-k);
		}
		return ans;
	}
}fen;

void add(int x, int v)
{
    fen.Add(n-1, v);
    fen.Add(x-1, -v);
}

int main()
{
    FAST;
    cin >> n;
    cin >> s;
    strcpy(r, s);
    reverse(r,r+n);
    Loop(i,0,256)
        f[i] = -1;
    Loop(i,0,n)
        if(f[s[i]] == -1)
            f[s[i]] = i;
    Loop(i,1,n)
        add(i,1);
    ll ans = 0;
    Loop(k,0,n)
    {
        ans += fen.Get(f[r[k]]);
        add(f[r[k]], -1);
        s[f[r[k]]] = '#';
        while(f[r[k]] < n && s[f[r[k]]] != r[k])
            ++f[r[k]];
    }
    cout << ans << '\n';
}