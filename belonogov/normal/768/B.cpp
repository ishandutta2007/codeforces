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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll answer;
ll l, r;

void go(ll tl, ll tr, ll x) {
    //db3(tl, tr, x);
    if (tr <= l || r <= tl) return;
    //db2(tl, tr, );
    ll sz = (tr - tl);
    assert(sz % 2 == 1);
    ll mid = (tl + tr) / 2;
    if (x % 2 == 1 && l <= mid && mid < r) {
        //db3("add", tl, tr);
        answer++;
    }
    if (tr - tl == 1) 
        return;
    go(tl, mid, x / 2);
    go(mid + 1, tr, x / 2);


}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    ll x;
    cin >> x;
    cin >> l >> r;
    l--;
    r--;
    ll xx = x;
    ll all = 0;
    ll cof = 1;
    for (; x > 1; ) {
        all += cof;
        cof *= 2;
        x /= 2;
    }
    all += cof;
    r++;
    go(0, all, xx);

    cout << answer << endl;



    return 0;
}