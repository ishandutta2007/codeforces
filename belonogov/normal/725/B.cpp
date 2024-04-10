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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;


void read() {
    ll n;
    char ch;
    scanf("%lld%c", &n, &ch);
    ll x = 0; 
    if (ch == 'f') x = 1;
    if (ch == 'e') x = 2;
    if (ch == 'd') x = 3;
    if (ch == 'a') x = 4;
    if (ch == 'b') x = 5;
    if (ch == 'c') x = 6;
    n--;
    x += n / 4 * (12 + 4);
    n %= 4;
    if (n == 0) x += 0;
    if (n == 1) x += 7;
    if (n == 2) x += 0;
    if (n == 3) x += 7;
    
    cout << x << endl;

}

void solve() {

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
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