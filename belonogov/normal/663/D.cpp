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
const int N = 5555;
const long long INF = 1e9 + 19;

int n;
int a[N][3];
bool can[N][3];
int sumH[3];
int cando[3];



void read() {
    scanf("%d", &n);
    vector < vector < int > > tmp;
    tmp.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            scanf("%d", &x);
            tmp[i].pb(x);
        }
    }
    sort(tmp.begin() + 1, tmp.end(), [](vector < int > a, vector < int > b) {
                int fa = 0, fb = 0;
                for (auto x: a) fa += x < 0;
                for (auto x: b) fb += x < 0;
                return fa > fb;
            });

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            if (tmp[i][j] < 0)
                can[i][j] = 1;
            a[i][j] = abs(tmp[i][j]);
        }
}

int sum[3];
int f[10];
int cost[10];
int tmp[3];
int hack[N];



int calcScore(int id, int mask, int g1, int g2, int g3) {
    tmp[0] = g1;
    tmp[1] = g2;
    tmp[2] = g3;
    int sum = 0;
    for (int i = 0; i < 3; i++) { 
        if (a[id][i] != 0 && (((mask >> i) & 1) == 0))
            sum += (cost[tmp[i]] / 250) * (250 - a[id][i]);
    }
    return sum;
}

void upd(int & a, int b) {
    a = min(a, b);
}

int preCost[N][3];

void solve() {
    cost[1] = 500;
    cost[2] = 1000;
    cost[3] = 1500;
    cost[4] = 2000;
    cost[5] = 2500;
    cost[6] = 3000;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            hack[i] |= (can[i][j] << j);
            if (a[i][j] > 0) {
                preCost[i][j] = 2 * (250 - a[i][j]);
            }
        }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            sum[j] += a[i][j] != 0;
            sumH[j] += can[i][j];
        }

    int total = 0;
    for (int j = 0; j < 3; j++)
        total += sumH[j];

    if (total > 90) {
        puts("1");
        return;
    }

    f[0] = n + 1;
    f[1] = n / 2 + 1;
    f[2] = n / 4 + 1;
    f[3] = n / 8 + 1;
    f[4] = n / 16 + 1;
    f[5] = n / 32 + 1;
    f[6] = 0;
    //for (int i = 1; i <= 6; i++)
        //cerr << i * 500 << " [" << f[i] << ", " << f[i - 1] - 1 << "]" << endl;


    //for (int i = 0; i < 3; i++)
        //db2(sum[i], sumH[i]);
    //exit(0);

    int mainCur = 1;
    for (;mainCur < n && hack[mainCur] > 0; mainCur++);

    int answer = n;



    for (int g1 = 1; g1 <= 6; g1++)
        for (int g2 = 1; g2 <= 6; g2++)
            for (int g3 = 1; g3 <= 6; g3++) {
                //g1 = 1;
                //g2 = 2;
                //g3 = 1;


                int g[3];
                g[0] = g1;
                g[1] = g2;
                g[2] = g3;

                int l[3];
                int r[3];
                bool flag1 = 1;
                //db("Here");
                //cerr << endl;
                for (int i = 0; i < 3; i++)  {
                    r[i] = sum[i] - f[g[i]];
                    l[i] = sum[i] - (f[g[i] - 1] - 1);
                    r[i] = min(r[i], sumH[i]);
                    l[i] = max(0, l[i]);
                    if (r[i] < l[i]) {
                        flag1 = 0;
                    }
                }


                if (!flag1) continue;

                int h0 = r[0];
                int h1 = r[1];
                int h2 = r[2];

                if (h0 < 0 || h1 < 0 || h2 < 0) continue;
                vector < vector < vector < vector < int > > > > dp(mainCur + 1);
                for (int i = 0; i <= mainCur; i++)
                    dp[i].resize(h0 + 1, vector < vector < int > > (h1 + 1,  vector < int > (h2 + 1, INF))); 
                dp[1][0][0][0] = 0;
                

                int myScore = calcScore(0, 0, g1, g2, g3) + (h0 + h1 + h2) * 100;
                //db(myScore);
                assert(h0 + h1 + h2 <= 90);
                for (int i = 1; i < mainCur; i++) {
                    for (int x = 0; x <= h0; x++)
                        for (int y = 0; y <= h1; y++)
                            for (int z = 0; z <= h2; z++) {
                                if (dp[i][x][y][z] >= INF) continue;

                                for (int mask = 0; mask < 8; mask++) {
                                    bool flag = 1;
                                    for (int j = 0; j < 3; j++)
                                        if (((mask >> j) & 1) == 1 && can[i][j] == 0)
                                            flag = 0;

                                    if (!flag)
                                        continue;

                                    int res = calcScore(i, mask, g1, g2, g3);
                                    //db2(i, res);
                                    int x1 = x;
                                    int y1 = y;
                                    int z1 = z;
                                    if (((mask >> 0) & 1)) x1++;
                                    if (((mask >> 1) & 1)) y1++;
                                    if (((mask >> 2) & 1)) z1++;
                                    if (x1 > h0 || y1 > h1 || z1 > h2) continue;
                                    if (res > myScore) {
                                        upd(dp[i + 1][x1][y1][z1], dp[i][x][y][z] + 1);
                                    }
                                    else {
                                        upd(dp[i + 1][x1][y1][z1], dp[i][x][y][z]);
                                    }
                                }
                            }
                }
                int cc = 0;
                for (int i = mainCur; i < n; i++) {
                    assert(hack[i] == 0);
                    int res = 0;
                    for (int j = 0; j < 3; j++)
                        res += preCost[i][j] * g[j]; 
                    cc += res > myScore;
                }
                          
                for (int x = l[0]; x <= r[0]; x++)
                    for (int y = l[1]; y <= r[1]; y++)
                        for (int z = l[2]; z <= r[2]; z++) {
                            answer = min(answer, dp[mainCur][x][y][z] + cc);
                        } 
            }    

    printf("%d\n", answer + 1);
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