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

int q , n , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        vector<pii> ans;
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
        }
        if(n > 1){
            ans.push_back({1 , n});
        }
        if((A[1] + A[n]) % 2 == 0){
            A[1] = A[n];
        }
        else{
            A[n] = 1;
        }
        for(int i = 2 ; i < n ; i++){
            if((A[i] + A[1]) % 2 == 0){
                ans.push_back({i , n});
            }
            else{
                ans.push_back({1 , i});
            }
        }
        cout << SZ(ans) << endl;
        for(pii i : ans){
            cout << i.X << sep << i.Y << endl;
        }
    }

    return 0;
}
/*

*/