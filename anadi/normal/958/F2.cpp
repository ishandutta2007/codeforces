#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

const int N = 2e5 + 7;

int n, m, T[N], P[N], cnt[N];

int main()
{
    _upgrade
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> T[i];
    for(int j = 1; j <= m; j++)
        cin >> P[j];
    int ile = 0, j = 0, sum = 0, ans = 1e9;
    for(int i = 1; i <= m; i++)
    {
        sum += P[i];
        if(P[i] == 0) ile++;
    }
    for(int i = 0; i < n; i++)
    {
        while(ile < m && j < n)
        {
            if(T[j] <= m)
            {
                cnt[T[j]]++;
                if(cnt[T[j]] == P[T[j]])
                    ile++;
            }
            j++;
        }
        if(ile == m)
        {
            ans = min(ans, j - i - sum);
        }
        if(T[i] <= m)
        {
            if(cnt[T[i]] == P[T[i]])
                ile--;
            cnt[T[i]]--;
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
	return 0;
}