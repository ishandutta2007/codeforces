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

const int MAXN = 100007;

int a[MAXN], b[MAXN], c[MAXN];
int p[MAXN], q[MAXN];
int ans[MAXN];
int n, m, s;

bool opr_sort_p(const int &i, const int &j)
{
    return a[i] < a[j];
}

bool opr_sort_q(const int &i, const int &j)
{
    return b[i] < b[j] || (b[i] == b[j] && c[i] > c[j]);
}


bool check(int center)
{
    int x = s;
    
    priority_queue < pair <int, int> > h;
//    cout << "\t" << center << endl;
    
    for (int i = m - 1, j = n - 1; i >= 0; ) {
        while (j >= 0 && a[p[i]] <= b[q[j]]) {
            h.push(make_pair(-c[q[j]], q[j]));
            j -= 1;
        }
//                cout << "  " << j << " " << q[j] << ": " << b[q[j]] << " " << c[q[j]] << endl;
        if (h.size() == 0) {
            return false;
        }
        int ind = h.top().second;
        h.pop();
        
        x -= c[ind];
//                cout << "   =" << x << endl;
        if (x < 0) {
            return false;
        }
        for (int z = 0; z < center && i >= 0; --i, ++z) {
            ans[p[i]] = ind;
        }
    }
    return true;
}


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
    
    while (cin >> n >> m >> s) {
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        
        for (int i = 0; i < m; ++i) {
            p[i] = i;
        }
        sort(p, p + m, opr_sort_p);
        
        for (int i = 0; i < n; ++i) {
            q[i] = i;
        }
        sort(q, q + n, opr_sort_q);

        int l = 1, r = m + 1;
        while (l < r) {
            int center = (l + r) / 2;
            
            if (check(center)) {
                r = center;
            } else {
                l = center + 1;
            }
        }
        if (r == m + 1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            check(r);
            for (int i = 0; i < m; ++i) {
                if (i) {
                    cout << " ";
                }
                cout << ans[i] + 1;
            }
            cout << "\n";
        }
    }
	return 0;
}