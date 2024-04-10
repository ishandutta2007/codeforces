#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second
#define pb push_back

typedef long long ll;      
typedef pair<int, int> pii;
typedef pair<long, long> pll;



const int N = 5010;
int n, a, b, dp[N], pre[N][N];
string s;

int main(){
    cin >> n >> a >> b;
    cin >> s;
    s = "$" + s;
    
    for(int i = n; i >= 1; i--)
        for(int j = i - 1; j >= 1; j--)
            if(s[i] == s[j])
                pre[j][i] = pre[j + 1][i + 1] + 1;
                                        
    for(int i = 1; i <= n; i++)
        dp[i] = i * a;

    for(int i = 1; i <= n; i++){
        int mx = 0;
        dp[i] = min(dp[i], dp[i - 1] + a);                
        for(int j = 1; j <= i; j++){
            int x = pre[j][i + 1];
            x = min(x, i - j + 1);
            mx = max(mx, i + x);
        }
        for(int j = i + 1; j <= mx; j++)
            dp[j] = min(dp[j], dp[i] + b);
    }

    cout << dp[n];
    return 0;
}