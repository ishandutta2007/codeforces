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
const ll LOG = 26;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , mark[LOG] , nxt[LOG] , par[LOG] , sz[LOG];
string s;

int Find(int v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
    v = Find(v); u = Find(u);
    if(v == u)  return;
    if(sz[v] < sz[u])   swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s;
        fill(nxt , nxt + LOG , -1);
        fill(mark , mark + LOG , 0);
        fill(par , par + LOG , -1);
        fill(sz , sz + LOG , 1);
        for(int i = 0 ; i < n ; i++){
            int c = s[i] - 'a';
            if(nxt[c] == -1){
                int mn = -1;
                for(int j = 0 ; j < LOG ; j++){
                    if(!mark[j])    mn = j;
                }
                for(int j = 0 ; j < LOG ; j++){
                    if(mark[j] || Find(j) == Find(c))   continue;
                    mn = j;
                    break;
                }
                nxt[c] = mn;
                mark[mn] = 1;
                Union(mn , c);
            }
            s[i] = nxt[c] + 'a';
        }
        cout << s << endl;
    }

    return 0;
}
/*

*/