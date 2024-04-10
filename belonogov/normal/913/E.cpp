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
#define db4(x, y, z, ww) cerr << "(" << #x << ", " << #y << ", " << #z << ", " << #ww << ") = (" << x << ", " << y << ", " << z << ", " << ww << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 3;
//const int F = pw(N);
const int M = 256;
const int INF = 1.01e9;
typedef vector<int> vi;




int pw3[20];

string myMin(string a, string b) {
    if (a.empty()) return b;
    if (b.empty()) return a;
    if (sz(a) != sz(b)) {
        if (a.size() < b.size())
            return a;
        return b;
    }
    return min(a, b);
}
string resF[M];
int maxF[M];

string getE(int mask, int mx);

string getF(int mask, int mx) {
    if (mx <= 0) return "";
    assert(0 <= mask && mask <= 255);
    if (resF[mask] == "" && maxF[mask] < mx) {
        maxF[mask] = mx;
        string best = getE(mask, mx - 2);
        if (best != "") {
            best = "(" + best + ")";
        }
        string tmp = getF(255 ^ mask, mx - 1);
        if (tmp != "") {
            tmp = "!" + tmp;
        }
        best = myMin(best, tmp);
        assert(sz(best) <= mx);
        resF[mask] = best;
    } 
    if (sz(resF[mask]) <= mx)
        return resF[mask];
    return "";
}




string resT[M];
int maxT[M];

string getT(int mask, int mx) {
    if (mx <= 0) return "";
    assert(0 <= mask && mask <= 255);
    if (resT[mask] == "" && maxT[mask] < mx) {
        maxT[mask] = mx;
        string best = getF(mask, mx);
        //db(best);

        int cnt1 = 8 - __builtin_popcount(mask);
        for (int comb = 0; comb < pw3[cnt1]; comb++) {
            int mask1 = 0;
            int mask2 = 0;
            int x = comb;
            for (int i = 0; i < 8; i++) {
                if (mask & pw(i)) {
                    mask1 |= pw(i);
                    mask2 |= pw(i);
                }
                else {
                    if (x % 3 == 1) {
                        mask1 |= pw(i);
                    }
                    if (x % 3 == 2) {
                        mask2 |= pw(i);
                    }
                    x /= 3;
                }
            }
            assert(x == 0);
            auto rt = getT(mask1, mx - 2);
            auto rf = getF(mask2, mx - 2);
            if (sz(rt) + sz(rf) + 1 <= mx && rt != "" && rf != "") {
                best = myMin(best,  rt + "&" + rf);
            }
        }

        //db2(best, mx);
        assert(sz(best) <= mx);
        resT[mask] = best;
    } 
    //db2(resT[mask], mx);
    //assert(sz(resT[mask]) <= mx);
    if (sz(resT[mask]) <= mx)
        return resT[mask];
    return "";
}




string resE[M];
int maxE[M];


string getE(int mask, int mx) {
    if (mx <= 0) return "";
    assert(0 <= mask && mask <= 255);
    if (resE[mask] == "" && maxE[mask] < mx) {
        //if (mask == 53) {
            //db2(mx, maxE[mask]);
        //}
        maxE[mask] = mx;
        string best = getT(mask, mx);
        //db(best);

        int cnt1 = __builtin_popcount(mask);
        for (int comb = 0; comb < pw3[cnt1]; comb++) {
            int mask1 = 0;
            int mask2 = 0;
            int x = comb;
            for (int i = 0; i < 8; i++) {
                if (mask & pw(i)) {
                    if (x % 3 == 0) {
                        mask1 |= pw(i);
                        mask2 |= pw(i);
                    } 
                    if (x % 3 == 1) {
                        mask1 |= pw(i);
                    }
                    if (x % 3 == 2) {
                        mask2 |= pw(i);
                    }
                    x /= 3;
                }
            }
            assert(x == 0);
            //if (mask1 == mask) {
            //} || mask2 == mask) {
                //continue;
            //}
            auto re = getE(mask1, mx - 2);
            auto rt = getT(mask2, mx - 2);
            //if (mx == 10 && mask == 53&& mask1 == 5 && mask2 == 48) {
                //db4(mask1, mask2, re, rt);
                //db(sz(re) + sz(rt));
            //}
            if (sz(re) + sz(rt) + 1 <= mx && re != "" && rt != "") {
                //if (mx == 10 && mask == 53) {
                    //db(re + "|" + rt);
                    //db2(mask1, mask2);
                //}
                best = myMin(best,  re + "|" + rt);
            }
        }
        //db2(best, mx);
        assert(sz(best) <= mx);

        resE[mask] = best;
    } 
    if (sz(resE[mask]) <= mx)
        return resE[mask];
    return "";
}



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    pw3[0] = 1;   
    for (int i = 1; i <= 8; i++) {
        pw3[i] = pw3[i - 1] * 3;
    }
    {
        int mask = 0;
        for (int i = 4; i < 8; i++)  mask |= pw(i);
        resF[mask] = "x";
        mask = 0;
        for (int i = 2; i < 4; i++)  mask |= pw(i);
        for (int i = 6; i < 8; i++)  mask |= pw(i);
        resF[mask] = "y";
        mask = 0;
        for (int i = 1; i < 8; i += 2) mask |= pw(i);
        resF[mask] = "z";
    }
    if (0) {
        //int mask = 255 ^ pw(1) ^ pw(6);
        int mask = 53;
        db(mask);
        cerr << getE(mask, 10) << endl;
        db(getE(mask, 10).size());
        return 0;
    }

    int mm = 0;
    for (int mask = 0; mask < M; mask++) {
        for (int deep = 1; deep < 50; deep++) {
            //assert(deep < 50);
            if (getE(mask, deep) != "") {
                mm = max(deep, mm);
                //break;
            }
        }
    }
    //db(mm);
    int hash = 0;
    for  (int i = 0; i < 256; i++) {
        hash += resE[i].size();
        //cout << resE[i] << endl;
    }
    //db(hash);


    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        char s[10];
        scanf("%s", s);
        for (int j = 0; j < 8; j++) {
            if (s[j] == '1') {
                mask |= pw(j);
            }
        }
        //db(mask);
        cout << resE[mask] << "\n";
        //db(resE[mask].size());
    }



    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}