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

int q , n , ps[MAXN];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s;
        int flag = 1 , mx = 1;
        for(int i = 0 ; i < n * 2 ; i++){
            ps[i + 1] = ps[i] + (s[i] == '(' ? 1 : -1);
        }
        for(int i = 1 ; i <= 2 * n ; i++){
            if(ps[i] < 0){
                flag = 0;
            }
            if(ps[i] > ps[mx]){
                mx = i;
            }
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        int l = MAXN , r = -MAXN , mxl = 0 , mxr = 2 * n;
        for(int i = 1 ; i <= 2 * n ; i++){
            if(ps[i] < 0){
                l = min(l , i);
                r = max(r , i);
            }
        }
        for(int i = 0 ; i < l ; i++){
            if(ps[i] > ps[mxl]){
                mxl = i;
            }
        }
        for(int i = r + 1 ; i <= 2 * n ; i++){
            if(ps[i] > ps[mxr]){
                mxr = i;
            }
        }
        flag = 1;
        for(int i = l - 1 ; i <= r + 1 ; i++){
            if(ps[i] > ps[mxl] + ps[mxr]){
                flag = 0;
            }
        }
        if(flag){
            cout << 1 << endl;
            cout << mxl + 1 << sep << mxr << endl;
            continue;
        }
        cout << 2 << endl;
        cout << 1 << sep << mx << endl;
        cout << mx + 1 << sep << 2 * n << endl;
    }

    return 0;
}
/*

*/