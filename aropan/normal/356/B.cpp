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

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
#define FOREACH(a, b) for(typeof((b).begin()) a = (b).begin(); a != (b).end(); ++a)


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    long long n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;
    if (a.size() < b.size())
    {
        swap(n, m);
        swap(a, b);
    }
    int g = gcd(a.size(), b.size());
    vector < vector <int> > v;
    v.resize(g);
    for (int i = 0; i < g; i++)
    {
        vector <int> &c = v[i];
        c.resize(26, 0);
        for (int j = 0, x = i; j < (int)a.size() / g; j++)
        {
            c[a[x] - 'a'] += 1;
            x += b.size();
            if (x >= (int)a.size())
                x %= a.size();
        }
    }
    
    long long ans = a.size() * n;
    long long L = a.size() * n;
    for (int i = 0; i < (int)b.size(); i++)
        ans -= v[i % g][b[i] - 'a'] * (L / (a.size() * (long long)b.size() / g));
    cout << ans << endl;
	return 0;
}