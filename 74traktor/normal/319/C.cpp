#include <bits/stdc++.h>

using namespace std;

#define int long long
#define X first
#define Y second

int a[100005];
int b[100005];
vector < pair < int, int > > Q;
vector < double > T;
int dp[100005];

double get(int k, int b, int k1, int b1){
    return (b1 - b) / (double)(k - k1);
}

int F(int x){
    double ok = x;
    int l = -1, r = T.size();
    while (r - l > 1){
        int m = (r + l) / 2;
        if (ok >= T[m]) l = m;
        else r = m;
    }
    //cout << l << " ";
    return Q[l].X * x + Q[l].Y;
}

void AddLine(int k, int b){
    while ((int)Q.size() > 1){
        int k1 = Q.back().X, b1 = Q.back().Y, n = Q.size();
        int k2 = Q[n - 2].X, b2 = Q[n - 2].Y;
        double x1 = (b1 - b) / (double)(k - k1), x2 = (b2 - b1) / (double)(k1 - k2);
        if (x2 < x1) break;
        Q.pop_back();
        T.pop_back();
    }
    T.push_back(get(k, b, Q.back().X, Q.back().Y));
    Q.push_back({k, b});
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    Q.push_back({b[1], 0});
    Q.push_back({b[2], a[2] * b[1]});
    T = {-1, get(b[1], 0, b[2], a[2] * b[1])};
    dp[2] = a[2] * b[1];
    for (int i = 3; i <= n; ++i){
        dp[i] = F(a[i]);
        int k = b[i], b = dp[i];
        AddLine(k, b);
    }
    cout << dp[n] << endl;
    return 0;
}