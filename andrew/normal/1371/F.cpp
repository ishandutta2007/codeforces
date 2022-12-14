#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


#define fi first
#define se second
#define p_b push_back
#define pll pair <ll, ll>
#define pii pair <int, int>
#define m_p make_pair
#define all(x) x.begin(), x.end()
#define sqr(x) ((x) * (x))
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define ifn(x) if(!(x))
#define fout(x) {cout << x << "\n"; return;}


using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 3123456;
const ll N = 2e5;
const ll inf = 1e18;
const ll buben = 338;
const ll mod = 1e9 + 7;
const ll step = 200003;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s) {cout << s << endl; exit(0);}
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct node{
    ll size;
    ll left[2], right[2], last[2], first[2], ans[2], last_1[2], first_1[2];
    bool fl;
};

node t[MAXN];

void push(int v){
    if(t[v].fl){
        if((v << 1) < MAXN){
            t[v << 1].fl ^= 1;
        }
        if((v << 1 | 1) < MAXN){
            t[v << 1 | 1].fl ^= 1;
        }
        t[v].fl = 0;

        swap(t[v].left[0], t[v].left[1]);
        swap(t[v].right[0], t[v].right[1]);
        swap(t[v].last[0], t[v].last[1]);
        swap(t[v].first[0], t[v].first[1]);
        swap(t[v].last_1[0], t[v].last_1[1]);
        swap(t[v].first_1[0], t[v].first_1[1]);
        swap(t[v].ans[0], t[v].ans[1]);

    }
    return;
}

string s;

node merge(node left, node right){
    node res;
    res.size = left.size + right.size;
    for(int i = 0; i < 2; i++){
        res.ans[i] = max(left.ans[i], right.ans[i]);

        res.last[i] = left.last[i];
        res.last_1[i] = left.last_1[i];
        res.first[i] = right.first[i];
        res.first_1[i] = right.first_1[i];

        if(left.right[i]){
            if(right.last[i]){
                res.ans[i] = max(res.ans[i], left.right[i] + right.last[i] + right.last_1[i]);
            }else{
                res.ans[i] = max(res.ans[i], left.right[i] + right.left[i]);
            }
        }

        if(right.left[i]){
            if(left.first[i]){
                res.ans[i] = max(res.ans[i], right.left[i] + left.first[i] + left.first_1[i]);
            }else{
                res.ans[i] = max(res.ans[i], right.left[i] + left.right[i]);
            }
        }

        if(left.left[i] == left.size){
            res.left[i] = left.left[i] + right.left[i];
        }else res.left[i] = left.left[i];

        if(right.right[i] == right.size){
            res.right[i] = right.right[i] + left.right[i];
        }else res.right[i] = right.right[i];

        if(right.first[i] == right.size){
            res.first[i] = right.first[i] + left.first[i];
            res.first_1[i] = left.first_1[i] + left.right[i];
        }else{
            if(right.first[i] + right.first_1[i] == right.size){
                res.first_1[i] = right.first_1[i] + left.right[i];
            }
        }

        if(left.last[i] == left.size){
            res.last[i] = left.last[i] + right.last[i];
            res.last_1[i] = right.last_1[i] + right.left[i];
        }else{
            if(left.last[i] + left.last_1[i] == left.size){
                res.last_1[i] = left.last_1[i] + right.left[i];
            }
        }

    }

    res.fl = 0;

    return res;
}

void build(int v, int tl, int tr){
    if(tl == tr){
        t[v].size = 1;

        if(s[tl] == '<'){
            t[v].left[0] = 1;
            t[v].first[0] = 1;
        }
        else{
            t[v].right[0] = 1;
            t[v].last[0] = 1;
        }


        char temp = '<';
        if(s[tl] == '<')temp = '>';

        if(temp == '<'){
            t[v].left[1] = 1;
            t[v].first[1] = 1;
        }
        else{
            t[v].right[1] = 1;
            t[v].last[1] = 1;
        }
    }else{
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

node answer;
bool F;

void modify(int v, int tl, int tr, int l, int r){
    if(l > r)return;
    push(v);
    if(tl == l && tr == r){
        t[v].fl ^= 1;
        push(v);
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm));
    modify(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    push(v << 1);
    push(v << 1 | 1);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

void get(int v, int tl, int tr, int l, int r){
    if(l > r)return;
    push(v);
    if(tl == l && tr == r){
        if(!F){
            F = 1;
            answer = t[v];
        }else answer = merge(answer, t[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    get(v << 1, tl, tm, l, min(r, tm));
    get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
}

int main(){

    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL


    int n, q;
    cin >> n >> q;

    cin >> s;
    s = "+" + s;
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        modify(1, 1, n, l, r);
        F = 0;
        get(1, 1, n, l, r);
        ll ans = max(answer.left[0], max(answer.right[0], answer.ans[0]));
        cout << ans << "\n";
    }


    return 0;
}