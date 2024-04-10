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
const int MOD = 1e9 + 7;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);   
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",  &a[i]);
    }

    vector<int> pr;
    for (int i = 2; i <= 70; i++) {
        bool ok = 1;
        for (int j = 2; j * j <= i; j++) {
            ok &= i % j != 0;
        }
        if (ok) {
            pr.pb(i);
        }
    }
    //vector<int> val(n);
    vector<pair<int,int>> st;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int mask = 0; 
        for (int j = 0; j < sz(pr); j++) {
            for (; x % pr[j] == 0; x /= pr[j]) {
                mask ^= pw(j);
            }
        }
        //val[i] = mask;

        for (auto h: st) {
            int mm = h.F;
            int id = h.S;
            if (mask & pw(id)) {
                mask ^= mm;
            }
        }
        //db2(mask, st.size());
        if (mask != 0) {
            int top = -1;
            for (int j = 0; j < sz(pr); j++) {
                if ((mask & pw(j)) != 0) {
                    top = j;
                    break;
                }
            }
            assert(top != -1);
            st.pb({mask, top});
            sort(all(st), [](pair<int,int> A, pair<int,int> B) {
                    //assert(A.S != B.S);
                    return A.S < B.S;
                    });
        }
    }
     
    ll answer = 1;
    for (int i = 0; i < n - sz(st); i++) {
        answer = answer * 2 % MOD;
    }

    cout << answer - 1 << endl;
    


    


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}