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

int q , n , m , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> A[i];
        }
        sort(A , A + m);
        vector<int> vec; A[m] = A[0] + n;
        for(int i = 0 ; i < m ; i++){
            vec.push_back(A[i + 1] - A[i] - 1);
        }
        sort(all(vec) , greater<int>());
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            int x = vec[i] - 4 * i;
            if(x == 1){
                ans++;
            }
            else if(x > 1){
                ans += x - 1;
            }
        }
        cout << endl;
        cout << n - ans << endl;
    }

    return 0;
}
/*

*/