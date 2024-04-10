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
const ll MOD = 998244353; //1e9 + 9;

int n , m , mark[MAXN] , A[MAXN] , L[MAXN] , R[MAXN] , psL[MAXN] , psR[MAXN] , res[MAXN] , rev[MAXN];
ll ans;

ll poww(ll x , ll y){
    ll ans = 1;
    for( ; y ; y >>= 1 , x = x * x % MOD){
        if(y & 1){
            ans = ans * x % MOD;
        }
    }
    return ans;
}

void NTT(vector<ll> &A , int inv){
    int n = SZ(A) , lg = 0 , x = n;
    while(x != 1){
        lg++;
        x /= 2;
    }
    for(int i = 1 ; i < n ; i++){
        rev[i] = ((rev[i >> 1] >> 1) + ((i & 1) << (lg - 1)));
        if(rev[i] > i){
            swap(A[i] , A[rev[i]]);
        }
    }
    for(int i = 1 ; i < n ; i *= 2){
        ll wn = poww(5 , MOD / 2 / i);
        if(inv) wn = poww(wn , MOD - 2);
        for(int j = 0 ; j < n ; j += i * 2){
            ll w = 1;
            for(int k = j ; k < j + i ; k++){
                ll v = A[k] , u = A[k + i] * w % MOD;
                A[k] = (v + u) % MOD;
                A[k + i] = (v + MOD - u) % MOD;
                w = w * wn % MOD;
            }
        }
    }
    if(inv){
        ll invn = poww(n , MOD - 2);
        for(int i = 0 ; i < n ; i++){
            A[i] = A[i] * invn % MOD;
        }
    }
}

vector<ll> conv(vector<ll> &A, vector<ll> &B){
    int n = 1;
    while(n < SZ(A) + SZ(B))    n *= 2;
    A.resize(n);
    B.resize(n);
    NTT(A , 0);
    NTT(B , 0);
    vector<ll> C(n , 0);
    for(int i = 0 ; i < n ; i++){
        C[i] = A[i] * B[i] % MOD;
    }
    NTT(C , 1);
    return C;
}

void solve(int l , int r){
    if(r - l == 1)  return;
    int mid = l + r >> 1;
    solve(l , mid);
    solve(mid , r);
    vector<ll> A;
    vector<ll> B;
    for(int i = l ; i < mid ; i++){
        A.push_back(L[i]);
    }
    for(int i = mid ; i < r ; i++){
        B.push_back(R[i]);
    }
    vector<ll> C = conv(A , B);
    for(int i = 0 ; i < SZ(C) ; i++){
        res[i + l + mid] = (res[i + l + mid] + C[i]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    for(int i = 0 ; i < m ; i++){
        int p; cin >> p;
        mark[p] = 1;
    }
    L[0] = R[n + 1] = 1;
    for(int i = 1 ; i <= n ; i++){
        L[i] = L[i - 1] * (mark[i] ? 2 : 1) % MOD;
        psL[i] = (psL[i - 1] + L[i]) % MOD;
    }
    for(int i = n ; i >= 1 ; i--){
        R[i] = R[i + 1] * (mark[i] ? 2 : 1) % MOD;
        psR[i] = (psR[i + 1] + R[i]) % MOD;
    }
    for(int i = 1 ; i <= n ; i++){
        ll cur = psR[2 * i];
        cur -= max(i - 1 , n - i);
        if(2 * i - n - 1 >= 0)  cur += psL[2 * i - n - 1];
        ans = (ans + cur * A[i] % MOD + MOD) % MOD;
    }
    solve(1 , n + 1);
    for(int i = 1 ; i <= n ; i++){
        ans = (ans + 1ll * res[2 * i] * A[i]) % MOD;
    }
    cout << ans * poww(L[n] - 1 , MOD - 2) % MOD << endl;

    return 0;
}
/*

*/