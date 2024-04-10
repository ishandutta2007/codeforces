#include <queue>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)

const int MAXN = 1000006;

priority_queue < pair <int, int> > h;
vector < pair <int, int > > e;
int l[MAXN], r[MAXN], w[MAXN];
int ans[MAXN];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    int n, m;
    cin >> n >> m;
    set <int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 1; i <= m; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        set <int> :: iterator b = s.lower_bound(l);
        set <int> :: iterator e = s.upper_bound(r);
        vector <int> v;
        while (b != e)
        {
            v.push_back(*b);
            ++b;
        }
        for (int j = 0; j < (int)v.size(); j++) 
            if (v[j] != w)
            {
                s.erase(v[j]);
                ans[v[j]] = w;
            }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
        if (i < n)
            cout << " ";
    }
    cout << endl;

	return 0;
}