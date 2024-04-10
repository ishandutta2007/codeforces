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



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    vector<string> name = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    int n;
    cin >> n;  
    set<pair<string, string>> q;
    for (int i = 0; i < n; i++) {
        string s, t;
        string tmp;
        cin >> s >> tmp >> t;
        assert(tmp == "likes");
        q.insert({s, t});
    }
    //for (auto x: q) {
        //db2(x.F, x.S);
    //}
    //dbv(name);

    vector<int> hp(3); 
    for (int i = 0; i < 3; i++) {
        cin >> hp[i];
    }
    pair<int,int> best = {INF * 2, 0};

    int m = 7;
    int all = 1;
    for (int i = 0; i < m; i++) {
        all *= 3;
    }
    for (int mask = 0; mask < all; mask++) {
        //db(mask);
        vector<int> team(m);
        int x = mask;
        vector<int> cnt(3);
        for (int i = 0; i < m; i++, x /= 3) {
            team[i] = x % 3;
            //db(team[i]);
            cnt[team[i]]++;
        }
        int mn = INF;
        int mx = 0; 
        int fr = 0;
        bool ok = 1;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] == 0) {
                ok = 0;
                break;
            }
            mn = min(mn, hp[i] / cnt[i]);
            mx = max(mx, hp[i] / cnt[i]);
        }
        //db(ok);
        if (ok == 0) continue;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (team[i] == team[j]) {
                    fr += q.count({name[i], name[j]});
                }
            }
        }
        //if (fr > 0) {
            //db(fr);
        //}
        //db(fr);
        int score = mx - mn;
        if (score < best.F || (best.F == score && best.S < fr)) {
            best = {score, fr};
        }
    }
    
    cout << best.F << " " << best.S << endl;



#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}