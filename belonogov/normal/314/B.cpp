#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1000;
const int p = 1e9;

char a[maxn];
char c[maxn];
int next[maxn][26];
int dp[maxn];
pair < int, int > go[maxn];
int t[maxn];
int t1[maxn];

int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int b, d, n, m, cnt;
    scanf("%d%d", &b, &d);
    scanf("%s", a);
    scanf("%s", c);
    n = strlen(a);
    m = strlen(c);
    for(int i = 0; i < n; i++)
        a[i + n] = a[i];

    memset(dp, -1, sizeof(dp));
    for(int i = n * 2 - 1; i >= 0; i--){
        if (i < n)
            for(int j = 0; j < 26; j++)
                next[i][j] = dp[j];
        dp[a[i] - 'a'] = i;
    }
 /*  for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++)
            epr("%d ", next[i][j]);
        epr("\n");
    }
    epr("\n");
*/
    for(int i = 0; i < n; i++){
       // epr("i: %d\n", i);
        pair < int, int > pos = mp(0, i);
        for(int j = 0; j < m; j++){
            if (next[pos.sc][c[j] - 'a'] == -1){
                printf("0\n");
                return 0;
            }
          // epr("%d %d\n", pos.fr, pos.sc);

            pos.sc = next[pos.sc][c[j] - 'a'];
            if (pos.sc >= n){
                pos.sc -= n;
                pos.fr++;
            }
        }
       // epr("%d %d\n", pos.fr, pos.sc);
       // epr("\n");
        go[i] = pos;
    }
    pair < int, int > p = mp(-1, n - 1);
    t[n - 1] = -1;
    memset(t1, -1, sizeof(t1));

 //   for(int i = 0; i < n; i++)
  //      epr("%d %d\n", go[i].fr, go[i].sc);
 //   epr("\n");
   // epr("3\n");
    for(int i = 0;; i++){
        t1[p.sc] = i;
       // epr("%d %d\n", p.fr, p.sc);
        if (p.fr > b){
            printf("%d\n", i);
            return 0;
        }
        if (t1[go[p.sc].sc] != -1){
          //  int x = t1[p.sc];
            p.fr += go[p.sc].fr;
            p.sc = go[p.sc].sc;
          //  epr("/* %d %d\n", (p.fr - t[p.sc]), (i + 1 - t1[p.sc]))
          //  epr("p %d %d\n", p.fr, p.sc);
          //  epr("t1 () /* %d %d %d %d\n", t1[p.sc], (b - p.fr - 1), (p.fr - t[p.sc]), (i + 1 - t1[p.sc]));
            cnt = t1[p.sc] + ((b - p.fr - 1) / (p.fr - t[p.sc]) + 1) * (i + 1 - t1[p.sc]);
            p.fr += (b - p.fr - 1) / (p.fr - t[p.sc]) * (p.fr - t[p.sc]);

          //  epr("p %d %d\n", p.fr, p.sc);
          //  epr("cnt %d\n", cnt);
            for(;p.fr < b; cnt++){
                p.fr += go[p.sc].fr;
                p.sc = go[p.sc].sc;
             //   epr("p %d %d\n", p.fr, p.sc);

            }
            cnt--;
         //   epr("%d\n", cnt);
            printf("%d\n", cnt / d);
            return 0;
        }
        else{
            p.fr += go[p.sc].fr;
            p.sc = go[p.sc].sc;
            t[p.sc] = p.fr;
        }

    }


    return 0;
}