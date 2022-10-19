#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;

class Fenwick
{
	int arr[N] = {};
public:
	void add(int k, int v)
	{
		k++;
		while (k < N)
		{
			arr[k] += v;
			k += k & (-k);
		}
	}
	int get(int k)
	{
		k++;
		int ans = 0;
		while (k > 0)
		{
			ans += arr[k];
			k -= k & (-k);
		}
		return ans;
	}
}fen;

set<int> T1;
int n;
int ans[N] = {};
int p[N];

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,2*n)
    {
        char c;
        cin >> c;
        if(c == '-')
        {
            int x;
            cin >> x;
            p[x] = i;
            fen.add(i, 1);
        }
        else
            T1.insert(i);
    }
    Loop(i,1,n+1)
    {
        auto it = T1.lower_bound(p[i]);
        if(it == T1.begin())
            Kill("NO");
        it--; int k = *it;
        if(fen.get(p[i]-1) - fen.get(k))
            Kill("NO");
        fen.add(p[i], -1);
        ans[k] = i;
        T1.erase(it);
    }
    cout << "YES\n";
    Loop(i,0,N)
        if(ans[i] != 0)
            cout << ans[i] << ' ';
}