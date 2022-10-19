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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int q , n , s , A[MAXN] , B[MAXN] , mark[MAXN] , pos[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s;
        fill(pos , pos + n + 5 , -1);
        fill(mark , mark + n + 5 , 0);
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
        }
        for(int i = 1 ; i <= n ; i++){
            cin >> B[i];
            if(B[i] != -1){
                pos[A[i]] = B[i];
                mark[B[i]] = 1;
            }
        }
        ll ans = 1;
        int cnt = 0 , ql = n;
        for(int i = n ; i >= 1 ; i--){
            while(ql >= max(1 , i - s)){
                if(mark[ql] == 0){
                    cnt++;
                }
                ql--;
            }
            if(pos[i] != -1){
                if(pos[i] < i - s){
                    ans = 0;
                    break;
                }
                continue;
            }
            ans = ans * cnt % MOD;
            cnt--;
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/