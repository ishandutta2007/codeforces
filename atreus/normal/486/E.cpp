#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100, INF = (1 << 30), mod = 1e9 + 7;
int n, lis, a[maxn], dp[maxn], lef[maxn], rig[maxn];
bool mark[maxn];

int main (){
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += '3';
    }
    memset (dp, 63, sizeof dp);
    dp[0] = - (1ll << 30);
    for (int i = 0; i < n; i++){
        int idx = lower_bound (dp, dp + n, a[i]) - dp;
        dp[idx] = a[i];
        lef[i] = idx - 1;
        a[i] *= -1;
        lis = max (lis, idx);
    }
    memset (dp, 63, sizeof dp);
    dp[0] = - (1ll << 30);
    for (int i = n - 1; i >= 0; i--){
        int idx = lower_bound (dp, dp + n, a[i]) - dp;
        dp[idx] = a[i];
        rig[i] = idx - 1;
    }
    for (int i = 0; i < n; i++){
        if (lef[i] + rig[i] + 1 < lis)
            s[i] = '1';
        else
            mark[i] = 1;
        a[i] *= -1;
    }
    int minimum = INF, maximum = -INF;
    for (int i = 0; i < n; i++){
        if (mark[i]){
            if (a[i] <= maximum)
                s[i] = '2';
            else
                maximum = a[i];
        }
    }
    for (int i = n - 1; i >= 0; i--){
        if (mark[i]){
            if (a[i] >= minimum)
                s[i] = '2';
            else
                minimum = a[i];
        }
    }
    cout << s << endl;
}