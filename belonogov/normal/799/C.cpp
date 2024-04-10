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

int nx(int i, int n) { return (i == n - 1)? 0: i + 1; }
int pr(int i, int n) { return (i == 0)? n - 1: i - 1; }

typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;

/// b p 

int solve(vector<pair<int,int>>& a, int p) {
    sort(all(a), [](pair<int,int> A, pair<int,int> B) {
                return A.S < B.S;
            });
    //db(a.size());
    int res = 0; 
    int mx = -INF;
    int cur = 0;
    vector<int> prefMax(sz(a) + 1);
    for (int i = 0; i < sz(a); i++) {
        prefMax[i + 1] = max(prefMax[i], a[i].F);
    }



    for (int i = (int)a.size() - 1; i >= 1; i--) {
        for (; cur < i && a[cur].S + a[i].S <= p; cur++) {
            mx = max(a[cur].F, mx);
        }
        if (cur <= i)
            res = max(res, mx + a[i].F);
        else {
            res = max(res, prefMax[i] + a[i].F);
        }
    }
    return res;
}

int getBest(vector<pair<int,int>> a) {
    sort(all(a));
    if (a.empty()) return -INF;
    return a.back().F;
}


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    //auto x = vector<pair<int,int>>();
    //solve(x, 3);
    //return 0;
    int n, c, d;
    scanf("%d%d%d", &n, &c, &d);
    vector<pair<int,int>> C;
    vector<pair<int,int>> D;
    for (int i = 0; i < n; i++) {
       int b, p;
        char ch;
        scanf("%d%d %c", &b, &p, &ch);
        if (ch == 'C') {
            if (p <= c) {
                C.pb({b, p});
            }
        }
        else if (ch == 'D') {
            if (p <= d) {
                D.pb({b, p});
            }
        }
        else {
            assert(false);
        }
    }
    int answer = 0;
    answer = max(answer, solve(C, c));
    answer = max(answer, solve(D, d));

    //db(answer);
    answer = max(answer, getBest(C) + getBest(D));

    cout << answer << endl;
    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}