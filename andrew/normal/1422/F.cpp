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
const ll N = 2e5 + 200;
const ll M = 2e5;
const ll inf = 1e10;
const ll mod = 1e9 + 7;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int mul(ll a, ll b){
    return (a * b) % mod;
}

struct node{
    int _time, ans;
    node *l, *r;
    node(): l(r=nullptr), _time(0), ans(1){}
};

int last[N], Local_time;
vector <int> step[N];
node *root[N];
vector <pii> p[N];

void build(node *v, int tl, int tr){
    if(tl != tr){
        v -> l = new node();
        v -> r = new node();
        int tm = (tl + tr) >> 1;
        build(v -> l, tl, tm);
        build(v -> r, tm + 1, tr);
    }
}

void modify(node *v, int tl, int tr, int pos, pii fraction){
    if(tl == tr){
        v -> ans *= fraction.fi;
        v -> ans /= fraction.se;
    }else{
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            if((v -> l) -> _time != Local_time){
                node *old = v -> l;
                v -> l = new node();
                (v -> l) -> ans = old -> ans;
                (v -> l) -> l = old -> l;
                (v -> l) -> r = old -> r;
                (v -> l) -> _time = Local_time;
            }
            modify(v -> l, tl, tm, pos, fraction);
        }else{
            if((v -> r) -> _time != Local_time){
                node *old = v -> r;
                v -> r = new node();
                (v -> r) -> ans = old -> ans;
                (v -> r) -> l = old -> l;
                (v -> r) -> r = old -> r;
                (v -> r) -> _time = Local_time;
            }
            modify(v -> r, tm + 1, tr, pos, fraction);
        }
        v -> ans = mul((v -> l) -> ans, (v -> r) -> ans);
    }
}

int get(node *v,  int tl, int tr, int l, int r){
    if(l > r)return 1;
    if(tl == l && tr == r)return v -> ans;
    int tm = (tl + tr) >> 1;
    return mul(get(v -> l, tl, tm, l, min(r, tm)), get(v -> r, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 2; i <= M; i++)if(!last[i]){
        last[i] = i;
        if(ll(i) * ll(i) <= M){
            for(int j = i * i; j <= M; j += i)last[j] = i;
        }
    }

    for(int i = 2; i <= M; i++){
        ll t = 1;
        while(t <= M){
            step[i].p_b(t);
            t *= (ll)i;
        }
    }
    
    root[0] = new node();

    build(root[0], 1, n);

    for(int i = 1; i <= n; i++){
        Local_time++;
        root[i] = new node();
        root[i] -> ans = root[i - 1] -> ans;
        root[i] -> l = root[i - 1] -> l;
        root[i] -> r = root[i - 1] -> r;
        root[i] -> _time = Local_time;
        int x = a[i];
        while(x != 1){
            int divider = last[x], st = 0;
            while(x % divider == 0){
                st++;
                x /= divider;
            }
            int _last = 0;
            while(!p[divider].empty() && p[divider].back().fi <= st){
                modify(root[i], 1, n, p[divider].back().se, {1, step[divider][p[divider].back().fi - _last]});
                _last = p[divider].back().fi;
                p[divider].pop_back();
            }
            modify(root[i], 1, n, i, {step[divider][st], 1});
            if(sz(p[divider])){
                modify(root[i], 1, n, p[divider].back().se, {1, step[divider][p[divider].back().fi - _last]});
                _last = st;
                modify(root[i], 1, n, p[divider].back().se, {step[divider][p[divider].back().fi - _last], 1});
            }
            p[divider].p_b({st, i});
        }
    }

    int q;
    cin >> q;

    int last_ans = 0;

    while(q--){
        int x, y, l, r;
        cin >> x >> y;
        l = (x + last_ans) % n + 1;
        r = (y + last_ans) % n + 1;
        if(l > r)swap(l, r);
        last_ans = get(root[r], 1, n, l, r);
        cout << last_ans << "\n";
    }

    return 0;
}