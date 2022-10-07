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

using namespace std;

#define F first
#define S second
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
const int N = 2111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


bool can[N];
int dist[N * 2];



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        can[x] = 1;
    }
    if (can[n]) {
        puts("1");
        return 0;
    }
    queue<int> q; 
    vector<int> e;
    memset(dist, 63, sizeof dist);
    for (int i = 0; i < N; i++)
        if (can[i]) {
            int x = i - n;
            e.pb(x);
            dist[x + N] = 1;
            q.push(x);
        }


    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto add: e) {
            int u = v + add;
            if (abs(u) <= 2000 && dist[u + N] > dist[v + N] + 1) {
                dist[u + N] = dist[v + N] + 1; 
                q.push(u);
            }
        }
    }


    if (dist[0 + N] > INF) {
        puts("-1");
    }
    else
        printf("%d\n", dist[0 + N]);






    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}