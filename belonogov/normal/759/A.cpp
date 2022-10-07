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

int n;
int p[N];
int b[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
}

void solve() {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += b[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            int v = i;
            for (; !use[v];) {
                use[v] = 1;
                v = p[v];
            }
            cnt++;
        }
    }
    int answer = 0;
    if (cnt >= 2)
        answer = cnt;
    if (sum % 2 == 0)
        answer++;
    cout << answer << endl;
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