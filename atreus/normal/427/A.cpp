#include <bits/stdc++.h>

using namespace std;

int dp[9000];

int main(){
    ios_base::sync_with_stdio(false);
    int n, t = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a > 0)
            t += a;
        if (a == -1 && t == 0)
            cnt ++;
        if (a == -1 && t > 0)
            t --;
    }
    cout << cnt << endl;
    }