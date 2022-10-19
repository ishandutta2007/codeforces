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

int q , n , mx[2] , B[MAXN] , nxt[MAXN] , flag[MAXN];
vector<int> vec[MAXN];
vector<pii> adj[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        fill(nxt , nxt + n + 5 , 0);
        fill(flag , flag + n + 5 , 0);
        fill(vec , vec + n + 5 , vector<int>());
        for(int i = 1 ; i <= n ; i++){
            cin >> B[i];
            vec[B[i]].push_back(i);
        }
        for(int i = 0 ; i <= n + 1 ; i++){
            if(SZ(vec[i]) == 0) continue;
            vector<pii> v;
            for(int j : vec[i]){
                v.push_back({SZ(vec[j]) , j});
            }
            sort(all(v));
            for(int j = 0 ; j + 1 < SZ(v) ; j++){
                nxt[v[j].Y] = v[j + 1].Y;
            }
            nxt[i] = v[0].Y;
            flag[i] = 1;
        }
        mx[0] = mx[1] = 0;
        int cur = (flag[0] ? 0 : n + 1) , col = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            col ^= flag[cur];
            cur = nxt[cur];
            ans.push_back(cur);
            mx[col] = max(mx[col] , cur);
        }
        int res = min(mx[0] , mx[1]);
        cout << (res != 0 ? res : min(B[1] , n)) << endl;
        for(int i : ans){
            cout << i << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/