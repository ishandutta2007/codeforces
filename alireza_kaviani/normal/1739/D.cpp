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

int q , n , k , mid , cnt , H[MAXN] , mx[MAXN];
vector<int> adj[MAXN];

void DFS(int v){
    mx[v] = 0;
    for(int u : adj[v]){
        H[u] = H[v] + 1;
        DFS(u);
        mx[v] = max(mx[v] , mx[u] + 1);
    }
    if(mx[v] >= mid - 1 && H[v] > 1){
        mx[v] = -MOD;
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> k;
        fill(adj , adj + n + 5 , vector<int>());
        for(int i = 2 ; i <= n ; i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
        int l = 0 , r = n;
        while(r - l > 1){
            mid = l + r >> 1; cnt = 0;
            fill(mx , mx + n + 5 , 0);
            DFS(1);
            if(cnt <= k)    r = mid;
            else    l = mid;
        }
        cout << r << endl;
    }

    return 0;
}
/*

*/