#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

vector <int> input;
int dp[100], pre[100];


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    input.resize(n);
    int all = 0;
    fop (i,0,n) cin >> input[i], all += input[i];
    FOP (i,n,0) pre[i] = (i == n - 1 ? input[i] : pre[i + 1] + input[i]);
    FOP (i,n,0) {
        if (i == n - 1) dp[i] = input[i];
        else {
            dp[i] = max(input[i] + pre[i + 1] - dp[i + 1], dp[i + 1]);
        }
    }
    cout << pre[0] - dp[0] << ' '<< dp[0];
}