#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    auto isPerm = [](vector<int> a) {
        return (set<int>(all(a))).size() == a.size();
    };

    
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    vector<int> dif;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            dif.pb(i);
    }
    if (dif.size() == 1) {
        int key = -1;
        int pos = dif[0];
        b.erase(b.begin() + pos);
        set<int> tmp(all(b));
        for (int j = 1; j <= n; j++) {
            if (tmp.count(j) == 0) {
                key = j;
                break;
            }
        }
        assert(key != -1);
        //db(key);
        a[pos] = key;
        for (auto x: a)
            printf("%d ", x); 
        puts("");
        assert(isPerm(a));

        return 0;

    }

    assert(dif.size() == 2);

    for (int tt = 0; tt < 2; tt++) {
        auto c = a;
        c[dif[tt]] = b[dif[tt]];
        if (isPerm(c)) {
            for (auto x: c)
                printf("%d ", x); 
            puts("");
            return 0;
        }
    }



    assert(false);
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}