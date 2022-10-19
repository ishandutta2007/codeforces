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

ll k , n , m , T[MAXN] , A[MAXN];
pii mx[MAXN];
vector<pii> ans , sum[MAXN];
vector<pair<pll , int>> obj;

int cmp(pair<pll , int> x , pair<pll , int> y){
    return x.X.X * y.X.Y > x.X.Y * y.X.X;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> k >> n >> m;
    for(int i = 1 ; i <= k ; i++)   cin >> A[i];
    for(int i = 1 ; i <= n ; i++){
        int x , b;
        cin >> T[i] >> x >> b;
        if(T[i] == 1){
            mx[x] = max(mx[x] , pii(b - A[x] , i));
        }
        if(T[i] == 2){
            sum[x].push_back({b , i});
        }
        if(T[i] == 3){
            obj.push_back({{b - 1 , 1} , i});
        }
    }
    for(int i = 1 ; i <= k ; i++){
        if(mx[i].Y != 0){
            sum[i].push_back(mx[i]);
        }
        sort(all(sum[i]) , greater<pii>());
        for(auto &[b , ind] : sum[i]){
            obj.push_back({{b , A[i]} , ind});
            A[i] += b;
        }
    }
    sort(all(obj) , cmp);
    if(SZ(obj) > m) obj.resize(m);
    for(auto &i : obj){
        ans.push_back({T[i.Y] , i.Y});
    }
    sort(all(ans));
    cout << SZ(ans) << endl;
    for(pii i : ans){
        cout << i.Y << sep;
    }

    return 0;
}
/*

*/