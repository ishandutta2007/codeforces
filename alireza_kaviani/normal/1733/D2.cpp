#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 5010;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , x , y , A[MAXN] , dp[MAXN];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        fill(A , A + MAXN , 0);
        fill(dp , dp + MAXN , INF);
        cin >> n >> x >> y >> s >> t;
        vector<int> vec;
        for(int i = 0 ; i < n ; i++){
            A[i + 1] = (s[i] == t[i] ? 0 : 1);
            if(A[i + 1]){
                vec.push_back(i + 1);
            }
        }
        x = min(x , y * 2);
        if(SZ(vec) % 2 == 1){
            cout << -1 << endl;
            continue;
        }
        if(SZ(vec) == 2 && vec[0] + 1 == vec[1]){
            cout << x << endl;
            continue;
        }
        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            if(A[i] == 0){
                dp[i] = dp[i - 1];
                continue;
            }
            int cnt = 0;
            dp[i] = dp[i - 1] + y;
            for(int j = i - 1 ; j >= 1 ; j--){
                if(A[j] == 1){
                    dp[i] = min(dp[i] , dp[j - 1] + cnt * y + (i - j) * x * 2);
                    cnt++;
                }
            }
        }
        cout << dp[n] / 2 << endl;
    }

    return 0;
}
/*

*/