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

int q , n;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s;
        vector<pii> ans;
        vector<int> vec;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1') cnt++;
        }
        if(cnt % 2 == 1 || cnt == 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                ans.push_back({i , (i + 1) % n});
            }
            else{
                vec.push_back({(i + 1) % n});
            }
        }
        for(int i = 1 ; i < SZ(vec) ; i++){
            ans.push_back({vec[0] , vec[i]});
        }
        for(pii i : ans){
            cout << i.X + 1 << sep << i.Y + 1 << endl;
        }
    }

    return 0;
}
/*

*/