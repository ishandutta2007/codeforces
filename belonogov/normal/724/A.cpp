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

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;


int getId() {
    string s;
    cin >> s;
    if (s.substr(0, 2) == "mo") return 0;
    if (s.substr(0, 2) == "tu") return 1;
    if (s.substr(0, 2) == "we") return 2;
    if (s.substr(0, 2) == "th") return 3;
    if (s.substr(0, 2) == "fr") return 4;
    if (s.substr(0, 2) == "sa") return 5;
    if (s.substr(0, 2) == "su") return 6;
    assert(false);
}

void read() {
    int x = getId();
    int y = getId();
    if ((x + 3) % 7 == y || (x + 2) % 7 == y || (x + 0) % 7 == y)
        puts("YES");
    else
        puts("NO");



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