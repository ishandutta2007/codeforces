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

const int MAXK = 50;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    int n;
    cin >> n;
    vector < pair <int, int> > a;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    set <int> s;
    s.insert(0);
    s.insert(n + 1);
    
    long double ans = 0;
    for (int I = 0; I < n; ++I) {
        int i = a[I].second;
        s.insert(i);
        set <int> :: iterator it;
        int p;
        
        long double l, r;
        l = r = 0;

        it = s.find(i);
        p = i;

        for (int j = 1; j <= MAXK && it-- != s.begin(); ++j) {
            l += (p - *it) / (long double)(1LL << j);
            p = *it;
        }
        
        it = s.find(i);
        p = i;
        for (int j = 1; j <= MAXK && ++it != s.end(); ++j) {
            r += (*it - p) / (long double)(1LL << j);
            p = *it;
        }
        ans += l * r * a[I].first * 2;
    }
    cout.precision(10);
    cout << fixed << ans / n / n << endl;
    
	return 0;
}