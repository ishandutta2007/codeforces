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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, a, b, k;
char s[N];

void read() {
    scanf("%d%d%d%d", &n, &a, &b, &k);
    scanf("%s", s);
}

void solve() {
    vector<int> pos; 
    for (int i = 0; i < n; ) {
        for (; i < n && s[i] == '1'; i++);

        if (i == n) break;
        int j = i;
        for (; i < n && s[i] == '0'; i++);

        j += b - 1;
        for (; j < i; j += b)
            pos.pb(j);
    }
    assert((int)pos.size() >= a); 
    int res = (int)pos.size() - (a - 1);
    printf("%d\n", res);
    for (int i = 0; i < res; i++)
        printf("%d ", pos[i] + 1);
    puts("");
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