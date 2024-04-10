#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = (int)2e5 + 100;
const int MAXN = (int)2e5;
char S[N_], T[N_];
bool T_chk[30];
int T_cnt;

int SN, TN;

const int hash_num = 3;
const ll hash_val[] = { 109, 1009, (ll)1e5 + 9 };
const ll hash_mod[] = { (ll)1e15 + 37, (ll)1e13 + 37, (ll)1e10 + 19 };
ll hash_pow[hash_num][N_];

ll sum_pw[N_];
unordered_map<ll, int> wh[hash_num];

bool ans[N_];

ll current_sum[hash_num][26];
int match[26];


int main() {
#ifndef ONLINE_JUDGE
    freopen("F.in", "r", stdin);
    freopen("F.out", "w", stdout);
#endif
    
    /*  */
    for (int h = 0; h < hash_num; h++) {
        hash_pow[h][0] = 1;
        for (int i = 1; i <= MAXN+1; i++) hash_pow[h][i] = (hash_pow[h][i - 1] * hash_val[h]) % hash_mod[h];
    }

    /*  */
    scanf("%d%d%s%s", &SN, &TN, S + 1, T + 1);
    
    for (int i = 1; i <= TN; i++) {
        if (!T_chk[T[i] - 'a']) T_cnt++;
        T_chk[T[i] - 'a'] = true;
    }

    for (int h = 0; h < hash_num; h++) {
        for (int c = 0; c < 26; c++) sum_pw[c] = 0;
        for (int i = 1, j = TN - 1; i <= TN; i++, j--) {
            (sum_pw[T[i] - 'a'] += hash_pow[h][j]) %= hash_mod[h];
        }
        for (int c = 0; c < 26; c++) if (T_chk[c]) wh[h][sum_pw[c]] = c;
    }

    for (int i = 1; i <= SN; i++) {
        bool chk = true;
        for (int h = 0; h < hash_num; h++) {
            /* add S[i]*/
            for (int c = 0; c < 26; c++) {
                (current_sum[h][c] *= hash_val[h]) %= hash_mod[h];
                if (c == S[i] - 'a') (++current_sum[h][c]) %= hash_mod[h];
                if (i >= TN && c == S[i-TN] - 'a') {
                    current_sum[h][c] -= hash_pow[h][TN];
                    (current_sum[h][c] += hash_mod[h]) %= hash_mod[h];
                }
                match[c] = -1;
            }

            int cnt_c = 0;

            for (int c = 0; c < 26; c++) if (current_sum[h][c] != 0) {
                ++cnt_c;
                if (wh[h].count(current_sum[h][c])) { //    
                    int d = wh[h][current_sum[h][c]];
                    if (match[d] == -1 || match[d] == c) match[d] = c; else chk = false;
                    if (match[c] == -1 || match[c] == d) match[c] = d; else chk = false;
                }
                else {
                    chk = false;
                }
            }

            if (cnt_c != T_cnt) chk = false;
        }
        if (chk) {
            assert(i - TN + 1 >= 1);
            ans[i - TN + 1] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= SN; i++) if (ans[i]) ++cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= SN; i++) if (ans[i]) printf("%d ", i);


    return 0;
}