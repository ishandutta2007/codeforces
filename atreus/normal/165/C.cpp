#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

const int maxn = 1e6 + 500;
int dp[maxn];
int n;
string s;

int first (int andice){
    int l = andice - 1;
    int r = s.size();
    while (r - l > 1){
        int x = (r + l) / 2;
        if (dp[x] - dp[andice] + 1 >= n)
            r = x;
        else
            l = x;
    }
    return r;
}

int last (int andice){
    int l = andice;
    int r = s.size();
    while (r - l > 1){
        int x = (r + l) / 2;
        if (dp[x] - dp[andice] + 1 <= n)
            l = x;
        else
            r = x;
    }
    return l;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    dp[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++){
        if (s[i] == '0')
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + 1;
    }
    long long ans = 0, k = 1;
    if (n == 0){
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '1'){
                k = 1;
                continue;
            }
            int l = first(i);
            int r = last(i);
            ans += k * (r - l + 1);
            k ++;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0'){
            k ++;
            continue;
        }
        int l = first(i);
        int r = last(i);
        ans += k * (r - l + 1);
        k = 1;
    }
    cout << ans << endl;
}