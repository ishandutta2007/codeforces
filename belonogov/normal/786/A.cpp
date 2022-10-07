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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int UD = 0;
const int LOSE = 1;
const int WIN = 2;


int main(){
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
    //assert(freopen(TASK".out", "w", stdout));
#endif
    int n;
    vector<int> dp[2];
    vector<int> deg[2];
    vector<int> status[2];
    vector<int> e[2];
    scanf("%d", &n);
    for (int t = 0; t < 2; t++) {
        dp[t].resize(n);
        deg[t].resize(n);
        status[t].resize(n);
    }
    for (int t = 0; t < 2; t++) {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            e[t ^ 1].pb(x);
            //db2(t, x);
        }
        for (int i = 0; i < n; i++)
            deg[t][i] = k;
    }
    queue<pair<int,int>> q;
    q.push({0, 0});
    q.push({1, 0});
    status[0][0] = LOSE;
    status[1][0] = LOSE;

    while (!q.empty()) {
        int turn = q.front().F;
        int pos = q.front().S;
        //db2(turn, pos);
        q.pop();
        for (auto shift: e[turn]) {
            int v = (pos - shift + n) % n;
            if (status[turn ^ 1][v] == UD && (status[turn][pos] == LOSE || (status[turn][pos] == WIN && --deg[turn ^ 1][v] == 0))) {
                status[turn ^ 1][v] = 3 - status[turn][pos]; q.push({turn ^ 1, v});
            }
        }
    }


   

    for (int t = 0; t < 2; t++) {
        for (int i = 1; i < n; i++) {
            if (status[t][i] == UD) cout << "Loop ";
            if (status[t][i] == WIN) cout << "Win ";
            if (status[t][i] == LOSE) cout << "Lose ";
        }
        cout << endl;
    }



    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}