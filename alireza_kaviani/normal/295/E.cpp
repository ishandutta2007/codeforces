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
#define rc         lc | 1

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 8e18; //998244353; //1e9 + 9;

struct Node{
    ll cnt , sum , ans;
    Node(){
        cnt = sum = ans = 0;
    }
};

ll n , q , A[MAXN] , B[MAXN];
vector<pair<ll, pll>> Q;
vector<ll> compress;
Node seg[MAXN << 2];

Node merge(Node L , Node R){
    Node ans;
    ans.cnt = L.cnt + R.cnt;
    ans.sum = L.sum + R.sum;
    ans.ans = L.ans + R.ans + R.sum * L.cnt * 2;
    return ans;
}

void modify(int pos , ll val , int cnt , int id = 1 , int l = 0 , int r = MAXN){
    if(r - l == 1){
        seg[id].cnt = cnt;
        seg[id].sum = val;
//        cout << "DEBUG " << pos << sep << val << endl;
        return;
    }
    int mid = l + r >> 1;
    if(pos < mid)   modify(pos , val , cnt , lc , l , mid);
    else modify(pos , val , cnt , rc , mid , r);
    seg[id] = merge(seg[lc] , seg[rc]);
}

Node get(int ql , int qr , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return seg[0];
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return merge(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int compressValue(ll x){
    return lower_bound(all(compress) , x) - compress.begin();
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i]; B[i] = A[i];
        compress.push_back(B[i]);
    }
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        int type , x , y;
        cin >> type >> x >> y;
        Q.push_back({type , {x , y}});
        if(type == 1){
            B[x] += y;
            compress.push_back(B[x]);
        }
    }
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    for(int i = 1 ; i <= n ; i++){
//        cout << A[i] << sep << compressValue(A[i]) << endl;
        modify(compressValue(A[i]) , A[i] , 1);
    }
    for(pair<ll , pll> i : Q){
        int type = i.X , x = i.Y.X , y = i.Y.Y;
        if(type == 1){
            modify(compressValue(A[x]) , 0 , 0);
            A[x] += y;
            modify(compressValue(A[x]) , A[x] , 1);
        }
        if(type == 2){
            int L = compressValue(x) , R = compressValue(y + 1);
            Node res = get(L , R);
//            cout << res.cnt << sep << res.sum << sep << res.ans << endl;
            cout << (res.ans + res.sum * (1 - res.cnt)) << endl;
        }
    }

    return 0;
}
/*

*/