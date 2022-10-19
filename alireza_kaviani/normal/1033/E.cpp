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

int n , mark[MAXN] , par[MAXN] , H[MAXN];
vector<int> layer[2];

int Query(vector<int> vec){
    cout << "? " << SZ(vec) << endl;
    for(int i : vec){
        cout << i << sep;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int Count(int v , vector<int> vec , int l = -1 , int r = -1){
    if(l == -1){
        l = 0; r = SZ(vec);
    }
    vector<int> V;
    for(int i = l ; i < r ; i++){
        V.push_back(vec[i]);
    }
    int A = Query(V);
    V.push_back(v);
    int B = Query(V);
    return B - A;
}

int Find(int v , vector<int> vec){
    if(SZ(vec) == 0 || Count(v , vec) == 0){
        return -1;
    }
    int l = 0 , r = SZ(vec);
    while(r - l > 1){
        int mid = l + r >> 1;
        if(Count(v , vec , 0 , mid) == 0)   l = mid;
        else    r = mid;
    }
    //cout << "Binary search " << v << sep << l << endl;
    return vec[l];
}

void DFS(int v , int col = 0){
    mark[v] = 1;
    layer[col].push_back(v);
    while(1){
        vector<int> vec;
        for(int i = 1 ; i <= n ; i++){
            if(!mark[i]){
                vec.push_back(i);
            }
        }
        int u = Find(v , vec);
        if(u == -1) break;
        par[u] = v;
        H[u] = H[v] + 1;
        //cout << "Edge " << v << sep << u << endl;
        DFS(u , 1 - col);
    }
}

void cycle(int v , int u){
    if(H[v] > H[u]) swap(v , u);
    vector<int> res;
    while(u != v){
        res.push_back(u);
        u = par[u];
    }
    res.push_back(v);
    cout << "N " << SZ(res) << endl;
    for(int i : res){
        cout << i << sep;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        if(!mark[i]){
            DFS(i);
        }
    }

    for(int i = 0 ; i < 2 ; i++){
        for(int v : layer[i]){
            vector<int> vec;
            for(int u : layer[i]){
                if(u != v){
                    vec.push_back(u);
                }
            }
            //cout << "SZ(vec) " << v << sep << SZ(vec) << endl;
            int u = Find(v , vec);
            if(u != -1){
                cycle(v , u);
                return 0;
            }
        }
    }

    cout << "Y " << SZ(layer[0]) << endl;
    for(int i : layer[0]){
        cout << i << sep;
    }
    cout << endl;

    return 0;
}
/*

*/