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
const int N = 1111;
const long long INF = 1e9 + 19;

vector < int > x[N];
vector < int > y[N];
pair < int, int > b[N];
bool use[N];
int n;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i].fr, &b[i].sc);        
        x[b[i].fr].pb(i);
        y[b[i].sc].pb(i);
    }
}

void dfs(int v) {
    use[v] = 1;
    for (auto u: x[b[v].fr])
        if (!use[u])
            dfs(u);

    for (auto u: y[b[v].sc])
        if (!use[u])
            dfs(u);
}
    
void solve() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!use[i]) {
            dfs(i); 
            cnt++;
        }

    cout << cnt - 1 << endl;


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