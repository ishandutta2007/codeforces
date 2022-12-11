#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int N = 104;

int pref[N][33];
char A[N], B[N], C[N];
int dp[N][N][N];
int who[N][N][N];
int chr[N][N][N];

void up(int a, int b, int c, int val, int W, int ch) {
    if (dp[a][b][c] < val) {
        //printf("up [%d][%d][%d] -> %d %d %c\n", a,b,c,val,W,'A'+ch);
        dp[a][b][c] = val;
        who[a][b][c] = W;
        chr[a][b][c] = ch;
    }
}

int main() {
    int al, bl, cl;
    scanf("%s%s%s", A, B, C);
    for (al = 0; A[al]; al++) ;
    for (bl = 0; B[bl]; bl++) ;
    for (cl = 0; C[cl]; cl++) ;
    for (int c = 0; c < cl; c++) {
        for (int k = 0; k < 26; k++) {
            for (pref[c][k] = c; pref[c][k] >= 0; pref[c][k]--) {
                if (C[pref[c][k]] != 'A' + k) {
                    continue;
                }
                bool ok = true;
                for (int i = 0; i < pref[c][k]; i++) {
                    if (C[i] != C[i+c-pref[c][k]]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
            pref[c][k]++;
            //printf("pref[%d][%c] = %d\n", c, 'A'+k, pref[c][k]);
        }
    }
    for (int a = 0; a <= al; a++) {
        for (int b = 0; b <= bl; b++) {
            for (int c = 0; c < cl; c++) {
                if (A[a] == B[b]) {
                    if (a < al && b < bl) {
                        up(a+1,b+1,pref[c][A[a]-'A'],dp[a][b][c]+1,a*N*N+b*N+c, A[a]-'A');
                    }
                }
                if (a < al) {
                    up(a+1,b,c, dp[a][b][c],a*N*N+b*N+c,-1);
                }
                if (b < bl) {
                    up(a,b+1,c, dp[a][b][c],a*N*N+b*N+c, -1);
                }
            }
        }
    }
    int wh = -1, best = -1;
    for (int c = 0; c < cl; c++) {
        if (dp[al][bl][c] > best) {
            best = dp[al][bl][c];
            wh = c;
        }
    }
    if (best == 0) {
        printf("0\n");
        return 0;
    }
    string result(best, ' ');
    while (dp[al][bl][wh] > 0) {
        //printf("al = %d, bl = %d, wh = %d\n", al, bl, wh);
        result[dp[al][bl][wh]-1] = 'A'+chr[al][bl][wh];
        int tmp = who[al][bl][wh];
        wh = tmp % N;
        tmp /= N;
        bl = tmp % N;
        al = tmp / N;
    }
    printf("%s\n", result.c_str());
    return 0;
}