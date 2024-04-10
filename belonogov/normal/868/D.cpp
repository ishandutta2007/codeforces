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
const int F = 10;


struct Str {
    bitset<pw(F + 1)> b;
    string pref;
    string suf;
};



int makeMask(int mask, int len) {
    int x = (pw(F - len) - 1) << (len + 1);
    //db(x);
    return x | mask;
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d",  &n);
    vector<Str> data(n);
    //db(makeMask(235, 10));
    //db(makeMask(1, 9));
    //db(makeMask(1, 1));
    //return 0;
    forn(h, n) {
        string t;
        cin >> t;
        forn(i, min(F, sz(t))) {
            data[h].pref += t[i];
            data[h].suf += t[t.size() - 1 - i];
        }
        for (int len = 1; len <= F; len++) {
            for (int i = 0; i + len <= sz(t); i++) {
                int mask = 0;
                for (int j = 0; j < len; j++) {
                    if (t[i + j] == '1') {
                        mask |= pw(j); 
                    }
                }
                data[h].b[makeMask(mask, len)] = 1;
            }
        }
    }
    //db("done");
    int k;
    scanf("%d", &k);
    forn(t, k) {
        //db(t);
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        //db2(x, y);
        data.pb(Str());
        auto& last = data.back();
        last.pref = data[x].pref;
        for (int i = 0; sz(last.pref) < F && i < sz(data[y].pref); i++) {
            last.pref += data[y].pref[i];
        }
        last.suf = data[y].suf;
        for (int i = 0; sz(last.suf) < F && i < sz(data[x].suf); i++) {
            last.suf += data[x].suf[i];
        }
        last.b = data[x].b | data[y].b;
        
        for (int len = 1; len <= F; len++) {
            //db(len);
            for (int right = 1; right <= len - 1; right++) {
                int left = len - right;
                if (left <= sz(data[x].suf) && right <= sz(data[y].pref)) {
                    //db2(left, right);
                    int mask = 0;
                    for (int j = 0; j < left; j++) {
                        mask |= pw(j) * (data[x].suf[left - j - 1] - '0');
                    }
                    for (int j = 0; j < right; j++) {
                        mask |= pw(left + j) * (data[y].pref[j] - '0');
                    }
                    last.b[makeMask(mask, len)] = 1;
                }
            } 
        }

        //db("done");
        int answerCand = 1;
        for (;answerCand <= F; answerCand++) {
            int ok = 1;
            forn(mask, pw(answerCand)) {
                ok &= last.b[makeMask(mask, answerCand)];
            }
            if (!ok) {
                break;
            }
        }

        cout << answerCand - 1 << endl;

    }


    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}