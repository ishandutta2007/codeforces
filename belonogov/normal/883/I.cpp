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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(all(a));
    vector<int> pref;

    auto add = [&](int l, int r) {
        pref[l]++;
        pref[r]--;
    };


    auto check = [&](int d) {
        pref.assign(n + 1, 0);
        add(0, 1);
        int bal = 0;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            bal += pref[i];
            if (bal == 0) continue;
            int l = i + k;
            int pos = upper_bound(all(a), a[i] + d) - a.begin();
            if (l <= n && pos == n) {
                answer = 1;
                break;
            }
            if (l <= pos) {
                add(l, pos + 1);
            }
        }
        return answer;
    };

    int l = -1;
    int r = INF; 
    while (r - l > 1) {
        if (check((l + r) / 2)) {
            r = (l + r) / 2;
        }
        else {
            l = (l + r) / 2;
        }
    }
    cout << r << endl;

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}