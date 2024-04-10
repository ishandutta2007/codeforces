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
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 5400;
const int inf = 1e9;

char s[100000];
int cnt[maxn];
int dp[maxn][maxn];
int p[maxn][maxn];
string ans;

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, r, l;
    scanf("%s", s);
    n = strlen(s);
    if (n >= 2600){
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i] >= 100){
                for (int j = 0; j < 100; j++)
                    printf("%c", char(i + 'a'));
                printf("\n");
                return 0;
            }
        while(true);
    }
    memset(p, -1, sizeof(p));
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
        dp[i][i + 1] = 1;
    }
    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++){
            r = l + len;
            if (dp[l][r - 1] > dp[l][r]){
                dp[l][r] = dp[l][r - 1];
                p[l][r] = 1;
            }
            if (dp[l + 1][r] > dp[l][r]){
                dp[l][r] = dp[l + 1][r];
                p[l][r] = 0;
            }
            if (dp[l + 1][r - 1] + 2 > dp[l][r] && s[l] == s[r - 1]){
                dp[l][r] = dp[l + 1][r - 1] + 2;
                p[l][r] = 2;
            }
        }
    l = 0;
    r = n;
    ans = "";
    for (;;){

        int d = p[l][r];
        while (l > r);
        if (d == -1)
            break;
        if (d == 2){
            ans = ans + s[l];
            l++;
            r--;
        }
        if (d == 1)
            r--;
        if (d == 0)
            l++;
    }
    int len = ans.length();
    while (!(0 <= l && l < n));
    if (dp[0][n] % 2 == 1)
        ans = ans + s[l];
    for(int i = len - 1; i >= 0; i--){
        char ch = ans[i];
        ans = ans + ch;
    }
    while (dp[0][n] != (int)ans.length());
    if (dp[0][n] > 100){
        for (int i = 0; i < 50; i++)
            cout << ans[i];
        for (int i = 49; i >= 0; i--)
            cout << ans[i];
    }
    else
        cout << ans;


    return 0;
}