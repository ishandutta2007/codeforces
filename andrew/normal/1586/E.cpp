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
const int N = 4e5;
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int p[N], pr[N][19], tin[N], tout[N], stn, res[N];
vector <int> v[N];

int get(int x){
    if(p[x] != x)p[x] = get(p[x]);
    return p[x];
}

void dfs(int x, int p){
    pr[x][0] = p;
    for(int i = 1; i < 19; i++){
        pr[x][i] = pr[pr[x][i - 1]][i - 1];
    }
    tin[x] = ++stn;
    for(auto to : v[x])if(to != p){
        dfs(to, x);
    }
    tout[x] = stn;
}

bool is_less(int a, int b){
    return (tin[b] <= tin[a] && tout[a] <= tout[b]);
}

int lca(int a, int b){
    if(is_less(a, b)){
        return b;
    }
    if(is_less(b, a)){
        return a;
    }
    for(int i = 18; i >= 0; i--){
        if(!is_less(b, pr[a][i])){
            a = pr[a][i];
        }
    }
    return pr[a][0];
}


int main(){
    tout[0] = 1e9;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;   
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        if(get(a) != get(b)){
            p[get(a)] = get(b);
            v[a].p_b(b);
            v[b].p_b(a);
        }
    }

    dfs(1, 0);

    int q;
    cin >> q;

    vector <pii> st;
    
    while(q--){
        int a, b;
        cin >> a >> b;
        res[a] ^= 1;
        res[b] ^= 1;
        st.p_b({a, b});
    }

    bool fl = 0;

    for(int i = 1; i <= n; i++){
        if(res[i]){
            fl = 1;
            break;
        }
    }

    if(!fl){
        cout << "YES\n";
        for(auto i : st){
            vector <int> a, b;
            int c = lca(i.fi, i.se), x = i.fi;
            while(x != c){
                a.p_b(x);
                x = pr[x][0];
            }
            x = i.se;
            a.p_b(c);
            while(x != c){
                b.p_b(x);
                x = pr[x][0];
            }
            reverse(all(b));
            for(auto i : b){
                a.p_b(i);
            }
            b.clear();
            cout << a.size() << "\n";
            for(auto i : a){
                cout << i << " ";
            }
            cout << "\n";
            a.clear();
        }
    }else{
        cout << "No\n";
        int c = 0;
        for(int i = 1; i <= n; i++){
            if(res[i]){
                c++;
            }
        }
        if(c % 2 == 0){
            cout << c / 2 << "\n";
        }else{
            if(c == 1){
                cout << "2\n";
            }else{
                cout << (c + 1) / 2 << "\n";
            }
        }
    }

    return 0;
}