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
#define forn(i, n) for (int i = 0; i < (n); i++)
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
const ll SHIFT = 1e10;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
    freopen("test.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    map<ll, int> q;
    vector<set<ll>> tmp(n);
    forn(i, n) {
        string s;
        cin >> s;
        assert(s.size() == 9);
        for (int j = 0; j < sz(s); j++) {
            ll val = 0;
            for (int len = 1; len + j <= sz(s); len++) {
                val = val * 10 + s[j + len - 1] - '0';
                tmp[i].insert(val + SHIFT * len);
            }
        }
        for (auto x: tmp[i]) {
            q[x]++;
        }
    }
    
    forn(i, n) {
        ll res = -1;
        for (auto x: tmp[i]) {
            if (q[x] == 1) {
                res = x;
                break;
            }
        }
        //assert(res != -1);
        int len = res / SHIFT;
        string ans;
        forn(j, len) {
            ans.pb('0' + res % 10);
            res /= 10;
        }
        reverse(all(ans));
        cout << ans << "\n";

    }

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}