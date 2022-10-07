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
vector<int> t;
int dp[N];

void read() {
    scanf("%d", &n);
    t.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
}

void solve() {
    int cur90 = 0;
    int cur1440 = 0;
    for (int i = 0; i < n; i++) {   
        for (; cur90 < n && t[cur90] + 90 <= t[i]; cur90++);
        for (; cur1440 < n && t[cur1440] + 1440 <= t[i]; cur1440++);

        dp[i + 1] = dp[i] + 20;
        dp[i + 1] = min(dp[i + 1], dp[cur90] + 50);
        dp[i + 1] = min(dp[i + 1], dp[cur1440] + 120);
        printf("%d\n", dp[i + 1] - dp[i]);
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