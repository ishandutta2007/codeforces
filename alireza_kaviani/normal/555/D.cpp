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

int n , q , A[MAXN];
vector<pii> vec;

int solve(int pos , int l , int flag = 1){
//    cout << pos << sep << l << endl;
    int R = lower_bound(all(vec) , pii(vec[pos].X + l , MOD)) - vec.begin() - 1;
    int L = lower_bound(all(vec) , pii(vec[pos].X - l , -MOD)) - vec.begin();
    if(L == R)  return pos;
    int nxt = R;
    if(pos == R)    nxt = L;
    int len = abs(vec[pos].X - vec[nxt].X) , cnt = l / len;
    if(flag)    return solve(nxt , l - len , 0);
    l %= len;
    if(cnt % 2 == 0)    return solve(pos , l , 0);
    return solve(nxt , l , 0);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        vec.push_back({A[i] , i});
    }
    sort(all(vec));
    while(q--){
        int x , l;
        cin >> x >> l; x--;
        int ind = lower_bound(all(vec) , pii(A[x] , -MOD)) - vec.begin();
        cout << vec[solve(ind , l)].Y + 1 << endl;
    }

    return 0;
}
/*

*/