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



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vi a(n);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    vi pref;
    pref.pb(0);
    forn(i, n) {
        pref.pb(pref.back() + a[i]);
    }
    auto getSum = [&](int l, int r) {
        return pref[r] - pref[l];
    };
    int answer = pref[n];
    vector<int> pos;
    forn(i, n) {
        if (a[i] == 1000 && pos.size() < 12) {
            pos.pb(i);
        }  
    }
    pos.pb(-1);

    auto solve = [&](int when) {
        //db(when);
        int bonus = 0;
        int res = 0;
        forn(i, n) {
            if (when == i) {
                int x = min(a[i], bonus);        
                //db(x);
                bonus -= x;
            } 
            else {
                res += a[i] / 10;
                bonus += a[i] / 10;
                if (getSum(i + 1, n) < bonus) {
                    answer = min(answer, pref[n] - (res - (bonus - getSum(i + 1, n))));
                    //db(answer);
                    break;
                }
            }
            answer = min(answer, pref[n] - res);
            //db2(answer, 2);
        }
    };
    //db(getSum(2, 3));
    //solve(2);
    //return 0;

    for (auto x: pos) {
        solve(x);
    }


    int opt = (pref[n] / 11) / 100 * 100;
    //db2(pref[n] - answer, opt);
    //assert(pref[n] - answer <= opt);
            
    int cur = n - 1;
    int curSum = 0;
    bool sawOne = 0;
    for (; cur >= 0 && curSum + a[cur] <= opt; cur--) {
        curSum += a[cur];
        sawOne |= a[cur] == 1000;
    }
    if (sawOne) {
        answer = min(answer, pref[n] - opt);
    } 

    
    
    cout << answer << endl;
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}