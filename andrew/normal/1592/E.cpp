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
const int MAXN = 1123456;
const int M = pw(16);
const long long mod = 1e9 + 7;
const int N = 2e5;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

struct node{
    node *p[2];
    vector <int> v;
    node(){
        p[0] = p[1] = nullptr;
    }
};

node *root = new node();
int to;

void add(int x, int pos){
    node *q = root;
    for(int i = 19; i >= 0; i--){
        to = 0;
        if((x & pw(i))){
            to = 1;
        }
        if(q -> p[to] == nullptr){
            q -> p[to] = new node();
        }
        q = q -> p[to];
        q -> v.p_b(pos);
    }   
}

int l, ra, rb;

vector <int> :: iterator it;

void get(int xr, int nd, int le, int ri){
    node *q = root;
    for(int i = 19; i >= 0; i--){
        ra = bool((pw(i) & xr));
        rb = bool((pw(i) & nd));
        to = ra ^ rb;
        if(rb){
            if(q -> p[1 ^ to] != nullptr){
                it = lower_bound(all((q -> p[1 ^ to]) -> v), le);
                if(it != (q -> p[1 ^ to]) -> v.end() && *it <= ri){
                    l = min(l, *it);
                }
            }
        }
        if(q -> p[to] == nullptr){
            return;
        }
        q = q -> p[to];
    }   
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> a(n + 1), pref(n + 1);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }

    vector <pii> vc, vc1;

    int ans = 0, x;

    for(int i = 1; i <= n; i++){
        l = n + 1;
        add(pref[i - 1], i);
        vc.p_b({a[i], i});
        for(auto j : vc){
            if(vc1.empty()){
                vc1.p_b({(j.fi & a[i]), j.se});
            }else{
                x = (j.fi & a[i]);
                if(x == vc1.back().fi){
                    vc1.pop_back();
                }
                vc1.p_b({(j.fi & a[i]), j.se});
            }
        }

        swap(vc, vc1);
        vc1.clear();
        int last = 1;

        for(auto j : vc){
            get(pref[i], j.fi, last, j.se);
            last = j.se + 1;
        }
        ans = max(ans, i - l + 1);
    }

    cout << ans << "\n";

    return 0;
}