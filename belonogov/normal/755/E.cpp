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

int n, k;

void read() {
    scanf("%d%d", &n, &k);
}

void ret() {
    puts("-1");
    exit(0);
}

void solve() {
    if (k == 1 || n <= 3) {
        ret();
    } 
    if (k == 2) {
        if (n == 4) {
            ret(); 
        }
        else {
            printf("%d\n", n - 1);
            for (int i = 0; i < n - 1; i++)
                printf("%d %d\n", i + 1, i + 2);
        }
    }
    else {
        if (k != 3) {
            ret();
        }
        else {
            if (n == 4) {
                cout << 3 << endl;
                cout << "1 2" << endl;
                cout << "2 3" << endl;
                cout << "3 4" << endl;
            }
            else {
                vector<pair<int,int>> edge;
                edge.pb(mp(1, 2));
                edge.pb(mp(2, 3));
                edge.pb(mp(3, 4));
                for (int i = 5; i <= n; i++) {
                    edge.pb(mp(i, 3));
                    edge.pb(mp(i, 2));
                }
                printf("%d\n", (int)edge.size());
                for (auto x: edge)
                    printf("%d %d\n", x.F, x.S);
            }
        }


    }


}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}