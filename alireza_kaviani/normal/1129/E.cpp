#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
//#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , sz[MAXN] , mark[MAXN] , par[MAXN];
vector<int> vec;

int query(int r , int x){
    vector<int> v;
    for(int i = 0 ; i < r ; i++){
        if(!mark[vec[i]]){
            v.push_back(vec[i]);
        }
    }
    if(SZ(v) == 0)  return 0;
    //cout << "========" << endl;
    cout << 1 << endl << 1 << endl;
    cout << SZ(v) << endl;
    for(int i : v){
        cout << i << sep;
    }
    cout << endl;
    cout << x << endl;
    int res;
    cin >> res;
    return res;
}

int cmp(int x , int y){
    return sz[x] > sz[y];
}

void DFS(int v){
    mark[v] = 1;
    while(sz[v] > 1){
        int l = 0 , r = n + 1;
        while(r - l > 1){
            int mid = l + r >> 1;
            int cnt = query(mid , v);
            if(cnt == 0)    l = mid;
            else    r = mid;
        }
        if(r == n + 1){
            break;
        }
        sz[v] -= sz[vec[l]];
        par[vec[l]] = v;
        DFS(vec[l]);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        vec.push_back(i);
    }
    mark[1] = 1; sz[1] = n;
    for(int i = 2 ; i <= n ; i++){
        sz[i] = query(n , i); // TODO
    }
    sort(all(vec) , cmp);
    DFS(1);
    cout << "ANSWER" << endl;
    for(int i = 2 ; i <= n ; i++){
        cout << par[i] << sep << i << endl;
    }

    return 0;
}
/*

*/