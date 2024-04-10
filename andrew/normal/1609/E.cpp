 #include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5;
const int M = pw(16);
const long long mod = 998244353;
const int N = 5e5;
const int inf = 1e9;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int t[N][33];

int wh[33][33];

bool u(int &a, int b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

void merge(int x, int l, int r){
    for(int i = 0; i < 32; i++)t[x][i] = inf;

    for(int i = 0; i < 32; i++)if(t[l][i] != inf){
        for(int j = 0; j < 32; j++)if(t[r][j] != inf){
            if(wh[i][j] != -1) u(t[x][wh[i][j]], t[l][i] + t[r][j]);
        }
    }
}

int a[N];

void build(int v, int tl, int tr){
    if(tl == tr){
        for(int i = 0; i < 32; i++){
             t[v][i] = inf;
        }
        t[v][1] = t[v][2] = t[v][4] = 1;
        t[v][pw(a[tl])] = 0;
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v, v << 1, v << 1 | 1);
    }
}

void modify(int v, int tl, int tr, int pos, int val){
    if(tl == tr){        
        for(int i = 0; i < 32; i++){
            t[v][i] = inf;
        }
        t[v][1] = t[v][2] = t[v][4] = 1;
        t[v][pw(val)] = 0;
    }else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            modify(v << 1, tl, tm, pos, val);
        }else{
            modify(v << 1 | 1, tm + 1, tr, pos, val);
        }
        merge(v, v << 1, v << 1 | 1);
    }
}

void pre_calc(){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            int m = i | j;
            if((pw(0) & i) && (pw(1) & j)) m |= pw(3);
            if((pw(1) & i) && (pw(2) & j)) m |= pw(4);
            if((pw(0) & i) && (pw(4) & j)) m = -1;
            if((pw(3) & i) && (pw(2) & j)) m = -1;
            wh[i][j] = m;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;    

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        a[i + 1] = c - 'a';
    }

    pre_calc();
    build(1, 1, n);

    while(q--){
        int pos;
        char x;
        int val;
        cin >> pos >> x;
        modify(1, 1, n, pos, (int)x - 'a');        
        int ans = inf;
        for(int i = 0; i < 32; i++) {
            ans = min(ans, t[1][i]);                        
        }
        cout << ans << '\n';
    }
    
    return 0;
}