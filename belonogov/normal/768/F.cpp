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

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2e5 + 100;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

int f, w, h;
ll fact[N];
ll rfact[N];

ll rev(ll a, ll m) {
    if (a == 0) return 0;
    return (((1 - rev(m % a, a) * m) / a) + m) % m;
}


ll getC(int n, int k) {
    assert(0 <= k && k <= n);
    return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

ll calcDist(ll all, ll part, ll mn) {
    assert(part > 0);
    all -= mn * part;
    if (all < 0) return 0;
    return getC(all + part - 1, part - 1);
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d", &f, &w, &h);
    if (f == 0) {
        if (w <= h) {
            puts("0");
            return 0;
        }
        else {
            puts("1");
            return 0;

        }
    }
    if (w == 0) {
        puts("1"); 
        return 0;
    }

    int mx = max(f, max(w, h)) + 2; 
    mx *= 2;
    fact[0] = 1;
    for (int i = 1; i <= mx; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    rfact[mx] = rev(fact[mx], MOD);     
    for (int i = mx - 1; i >= 0; i--)
        rfact[i] = (rfact[i + 1] * (i + 1)) % MOD;


    ll good = 0;
    ll all = 0;


    //db(getC(0, 0));
    for (int cntW = 1; cntW <= w; cntW++) {
        //db(cntW);
        ll a = calcDist(w, cntW, 1);
            //getC(w + cntW - 1, cntW - 1);
        ll g = calcDist(w, cntW, (h + 1));         
        //ll rem = w - cntW * h;
        //if (rem >= 0)
            //g = getC(rem +  cntW - 1, cntW - 1);
            
        ll comb = 0;

        if (cntW > 1) {
            ll cntF = cntW - 1;
            //db(cntF);
            comb = (comb + calcDist(f, cntF, 1)) % MOD;
        } 

        {
            ll cntF = cntW;
            comb = (comb + calcDist(f, cntF, 1) * 2) % MOD;
        } 

        {
            ll cntF = cntW + 1;
            comb = (comb + calcDist(f, cntF, 1)) % MOD;
        } 

        good = (good + g * comb) % MOD;
        all = (all + a * comb) % MOD;
    }







    ll x = good * rev(all, MOD) % MOD;
    cout << x << endl;

    return 0;
}