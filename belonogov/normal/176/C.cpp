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


bool read() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int x = abs(x1 - x2) + 1;
    int y = abs(y1 - y2) + 1;
    if (x < y) swap(x, y);
    assert(x >= y);
    x--; 
    if (x < y) swap(x, y);

    if (y <= 3) {
        return x <= 4;
    }
    return 0;
}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        if (read())
            puts("First");
        else
            puts("Second");
        solve();
    }
    else {
        stress();
    }

    return 0;
}