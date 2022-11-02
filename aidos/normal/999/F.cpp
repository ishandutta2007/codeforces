#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
int k;
int a[50500];
int b[50500];
int c[50500];
int d[50500];
int dp[5050][505];
int get(int N, int K){
    if(N == 0) return 0;
    if(K == 0) return 0;
    int &res = dp[N][K];
    if(res != -1) return res;
    res=get(N, K-1);
    for(int i = 1; i <= k; i++){
        if(N<i) break;
        res = max(get(N-i, K-1) + c[i-1], res);
    }
    return res;
}
int calc(int x, int c2){
    int cnt = 0;
    for(int i = 0; i < n * k; i++)
        if(a[i] == x) cnt++;
    return get(cnt, c2);
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for(int i = 0; i < n * k; i++){
        cin >> a[i];
    }
    sort(a, a + n * k);
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < k; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        d[i] = b[i];
    sort(d, d + n);
    long long ans = 0;
    for(int i = 0; i < n; ){
        int j = i;
        while(i < n && d[i] == d[j]) i++;
        ans += calc(d[j], i - j);
    }
    cout << ans << "\n";
	return 0;
}