#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1600 + 2;
const int inf = 1e9;
const int T1 = 4;
const int T2 = 6;
const int minSz = 7;
const int QQ = 8;
const int step[8][2] = {
    {
        1, 0
    },
    {
        0, 1
    },
    {
        -1, 0
    },
    {
        0, -1
    },
    {
        1, 1
    },
    {
        -1, 1
    },
    {
        -1, -1 
    },
    {
        1, -1
    }
};

int a[maxn][maxn];
int b[maxn][maxn];
bool c[maxn][maxn];
bool use[maxn][maxn];
vector < int > answer;
vector < pair < int, int > > stack;
vector < pair < int, int > > d;
int n, m;


bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}


void f(int C) {
    int x, y;
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
           if (b[i][j] == C) {
               for (int t = 0; t < QQ; t++) {
                   x = i + step[t][0];
                   y = j + step[t][1];
                   if (check(x, y))
                       c[x][y] = 1;
               }
           } 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = C ^ (1 ^ c[i][j]);
}

void dfs1(int x, int y) {
    int x1, y1;
    use[x][y] = 1;
    d.pb(mp(x, y));
    for (int t = 0; t < QQ; t++) {
        x1 = x + step[t][0];
        y1 = y + step[t][1];
        if (check(x1, y1) && !use[x1][y1] &&  b[x1][y1] == 1 && a[x1][y1] == 1)
            dfs1(x1, y1);
    }
}
int sz;

void dfs2(int x, int y) {
    int x1, y1;
    sz++;
    //stack.pb(mp(x, y));
    use[x][y] = 1;
    for (int t = 0; t < QQ; t++) {
        x1 = x + step[t][0];
        y1 = y + step[t][1];
        if (check(x1, y1) && !use[x1][y1] && a[x1][y1] == 1 && b[x1][y1] == 0)
            dfs2(x1, y1);
    } 
}

char ff(int x) {
    return (x == 1) ? '#': ' ';
}


int main(){
#ifdef DEBUG
    freopen("21.out.txt", "r", stdin);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << tmp << " ";
    }
    cout << endl;
    freopen("21.in.txt", "r", stdin);
    //freopenk"out", "w", stdout);
#endif
    int x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j];
    for (int i = 0; i < T1; i++)
        f(0);
    for (int j = 0; j < T2; j++)
        f(1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
             if (b[i][j] == 1 && a[i][j] == 1 && !use[i][j]) {
                int cnt = 0;
                d.clear();
                dfs1(i, j);
                if ((int)d.size() < minSz)
                    continue;
                //cerr << "\\\\\\\\\\\\\\\\\\\n";
                for (int t = 0; t < (int)d.size(); t++) 
                    for (int tt = 0; tt < QQ; tt++) {
                        x = d[t].fr + step[tt][0];
                        y = d[t].sc + step[tt][1];
                        if (check(x, y) && !use[x][y] && b[x][y] == 0 && a[x][y] == 1) {
                            sz = 0;
                            //stack.clear();
                            dfs2(x, y);
                            //cerr << "sz : " <
                            if (sz > minSz)
                                cnt++;
                            //cerr << "sz: " << sz << endl;
                            //if (sz < 7) {
                                //cerr << "x y: " << x << " " << y << endl;
                                //for (int ttt = 0; ttt < (int)stack.size(); ttt++)
                                    //epr("x1 y1: %d %d\n", stack[ttt].fr, stack[ttt].sc);
                                //int T = 15;
                                //for (int ii = x - T; ii < x + T; ii++, epr("\n"))
                                    //for (int jj = y - T; jj < y + T; jj++) {
                                        //if (ii == x && jj == y)
                                            //epr("Y");
                                        //else
                                            //epr("%c", ff(a[ii][jj]));
                                    //}
                                //epr("\n");
                                //for (int ii = x - T; ii < x + T; ii++, epr("\n"))
                                    //for (int jj = y - T; jj < y + T; jj++) {
                                        //if (ii == x && jj == y)
                                            //epr("Y");
                                        //else
                                            //epr("%c", ff(b[ii][jj]));
                                    //}


                            //}
                        }
                    }
                answer.pb(cnt);
            }
    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < (int)answer.size(); i++)
        printf("%d ", answer[i]);
    printf("\n");
    return 0;
}