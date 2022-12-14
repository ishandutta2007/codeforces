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
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <pii> st;

int ask(vector <int> p){
    cout << "?";
    for(auto i : p)cout << " " << i;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main(){

    int n;
    cin >> n;
    vector <int> p(n, 2);

    for(int step = 0; step < n; step++){
        p[step] = 1;
        int x = ask(p);
        p[step] = 2;
        x--;
        if(x == -1 || x == step){
            continue;
        }
        st.p_b({step, x});
    }

    fill(all(p), 1);

    for(int step = 0; step < n; step++){
        p[step] = 2;
        int x = ask(p);
        p[step] = 1;
        x--;
        if(x == -1 || x == step){
            continue;
        }
        st.p_b({x, step});
    }

    vector <int> nxt(n, -1), pre(n, -1), ans(n);

    for(auto i : st){
        nxt[i.se] = i.fi;
        pre[i.fi] = i.se;
    }

    int fst = 0;

    for(int i = 0; i < n; i++){
        if(pre[i] == -1){
            fst = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        ans[fst] = i + 1;
        fst = nxt[fst];
    }

    cout << "! ";

    for(auto i : ans){
        cout << " " << i;
    }
    cout << endl;

    return 0;
}