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

int n , m , mark[MAXN];
vector<int> ans , adj[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        adj[u].push_back(v);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j : adj[i]){
            if(j < i && mark[j] == 0){
                mark[i] = 1;
            }
        }
    }
    for(int i = n ; i >= 1 ; i--){
        for(int j : adj[i]){
            if(j > i && mark[j] == 0){
                mark[i] = 1;
            }
        }
        if(!mark[i]){
            ans.push_back(i);
        }
    }
    cout << SZ(ans) << endl;
    for(int i : ans){
        cout << i << sep;
    }

    return 0;
}
/*

*/