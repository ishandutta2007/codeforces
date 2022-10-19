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
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , q , R[MAXN] , A[MAXN] , fen[MAXN] , cnt[MAXN] , ans[MAXN] , seg[MAXN << 2];
vector<int> compressA , compressR , vec[MAXN];
vector<pair<pii , int>> Q[MAXN];

int compress(int x){
    return lower_bound(all(compressA) , x) - compressA.begin();
}

void add(int x , int val){
    for(x++ ; x < MAXN ; x += x & -x)   fen[x] += val;
}

int get(int x){
    int ans = 0;
    for( ; x > 0 ; x -= x & -x) ans += fen[x];
    return ans;
}

void modify(int pos , int val , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id] = max(seg[id] , val);
        return;
    }
    int mid = l + r >> 1;
    if(pos < mid)   modify(pos , val , lc , l , mid);
    else modify(pos , val , rc , mid , r);
    seg[id] = max(seg[lc] , seg[rc]);
}

int get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return -1;
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return max(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(seg , seg + MAXN * 4 , -1);

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> R[i];
        compressR.push_back(R[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
        compressA.push_back(A[i]);
    }
    sort(all(compressA)); compressA.resize(unique(all(compressA)) - compressA.begin());
    sort(all(compressR)); compressR.resize(unique(all(compressR)) - compressR.begin());

    for(int i = 1 ; i <= n ; i++){
        A[i] = lower_bound(all(compressA) , A[i]) - compressA.begin();
        R[i] = lower_bound(all(compressR) , R[i]) - compressR.begin();
        vec[R[i]].push_back(i);
    }

    cin >> q;
    for(int i = 0 ; i < q ; i++){
        int x , y;
        cin >> x >> y;
        if(A[x] > A[y]) swap(x , y);
        int l = compressA[A[y]] - k , r = compressA[A[x]] + k + 1;
        Q[max(R[x] , R[y])].push_back({{compress(l) , compress(r)} , i});
    }

    for(int i = 0 ; i < MAXN ; i++){
        for(int j : vec[i]){
            add(A[j] , 1);
        }
        for(int j : vec[i]){
            int L = compressA[A[j]] - k , R = L + 2 * k + 1;
            cnt[j] = get(compress(R)) - get(compress(L));
            //cout << j << sep << cnt[j] << endl;
        }
    }

    for(int i = MAXN - 1 ; i >= 0 ; i--){
        for(int j : vec[i]){
            modify(A[j] , cnt[j]);
        }
        for(pair<pii , int> j : Q[i]){
            ans[j.Y] = get(j.X.X , j.X.Y);
        }
    }
    for(int i = 0 ; i < q ; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
/*

*/