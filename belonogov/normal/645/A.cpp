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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;


vector < char > f() {
    string s, t;
    cin >> s >> t;
    vector < char > a;
    a.pb(s[0]);
    a.pb(s[1]);
    a.pb(t[1]);
    a.pb(t[0]);
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == 'X') {
            a.erase(a.begin() + i);
            break;
        }
    }
    vector < char > mn = a;
    for (int i = 0; i < 3; i++) {
        char x = a[0];
        a.erase(a.begin()); 
        a.pb(x);
        mn = min(mn, a);
    }
    return mn;
}

void read() {
    auto r1 = f();
    auto r2 = f();
    if (r1 == r2) {
        puts("YES");
    }
    else
        puts("NO");

}

void solve() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}