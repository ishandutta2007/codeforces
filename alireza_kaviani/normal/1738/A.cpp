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
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , t[MAXN] , d[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        ll ans = 0;
        vector<ll> A , B;
        for(int i = 0 ; i < n ; i++){
            cin >> t[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin >> d[i];
            if(t[i] == 0){
                A.push_back(d[i]);
            }
            else{
                B.push_back(d[i]);
            }
            ans += d[i];
        }
        sort(all(A) , greater<ll>());
        sort(all(B) , greater<ll>());
        ll sz = min(SZ(A) , SZ(B));
        for(int i = 0 ; i < sz ; i++){
            ans += A[i] + B[i];
        }
        if(SZ(A) == SZ(B)){
            ans -= min(A.back() , B.back());
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/