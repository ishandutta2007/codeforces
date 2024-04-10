#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 5000 + 2;
const int inf = 1e9;

int a[maxn];
int b[maxn];
//vector < int > c[maxn];
vector < int > c;
set < int > q;

int gcd(int a, int b) {
    return b == 0? a: gcd(b, a % b);
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m;
    int ans = 0, res;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        q.insert(b[i]);
    }
    
    for (int i = n; i > 0; i--) {
        int d = a[0];
        for (int j = 1; j < i; j++)
            d = gcd(d, a[j]);
        if (d == 1)
            continue;
        c.clear(); 
        int t = d;
        for (int j = 2; j * j <= t; j++)
            for (; t % j == 0; t /= j, c.pb(j));
        if (t > 1)
            c.pb(t);
        res = 0;
        for (int j = 0; j < (int)c.size(); j++)
            if (q.find(c[j]) == q.end())
                res--;
            else
                res++;
        if (res > 0) {
            for (int j = 0; j < i; j++)
                a[j] /= d;
        }
    }
    //for (int i = 0; i < n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        int t = a[i];
        c.clear();
        for (int j = 2; j * j <= t; j++)
            for (; t % j == 0; t /= j, c.pb(j));
        if (t > 1)
            c.pb(t);
        for (int j = 0; j < (int)c.size(); j++)
            if (q.find(c[j]) == q.end())
                ans++;
            else
                ans--;
    }
    cout << ans << endl;
    return 0;
}