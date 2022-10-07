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

#define equal equalll
#define less lesss
const int N = 5e5 + 10; 
const long long INF = 1e9 + 19;
const int H = 40;

int q;
double dp[N][H];
double mul[N][H];
int p[N];
int cur;
int path[N];
int pcur;

void read() {
    scanf("%d", &q);
    //cerr << q << endl;
}

void solve() {
    cur = 1;
    dp[0][0] = 1;
    p[0] = -1;
    for (int i = 0; i <= q; i++)
        for (int j = 0; j < H; j++)
            mul[i][j] = 1;

    for (int i = 0; i < q; i++) {
        //db(i);
        int type, v;
        scanf("%d%d", &type, &v); v--;
        if (type == 1) {
            p[cur] = v;     
            int u = cur;
            pcur = 0;
            dp[cur][0] = 1;
            for (int h = 0; h < H && u != -1; h++) {
                path[pcur++] = u;
                u = p[u];
            }
            for (int i = 2; i < pcur; i++) 
                mul[path[i]][i] /= (1 - dp[path[i - 1]][i - 1] / 2);
            
            //db(pcur);
            //db2(path[0], path[1]);
            for (int i = 1; i < pcur; i++) {
                mul[path[i]][i] *= (1 - dp[path[i - 1]][i - 1] / 2);
                dp[path[i]][i] = 1 - mul[path[i]][i];
                //dp[path[i]][i] *= (1 - dp[path[i - 1]][i - 1] / 2);
                //dp[path[i]][i] = 1 - dp[path[i]][i];
            }
        

            cur++;
        }
        else if (type == 2) {
            double answer = 0;
            for (int i = 1; i < H; i++)
                answer += dp[v][i];
            printf("%.17f\n", answer);
        }
        else
            assert(false);
        //cerr << endl;
        //for (int i = 0; i < cur; i++, cerr << endl)
            //for (int j = 0; j < 3; j++)
                //cerr << dp[i][j] << " ";
    }

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
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