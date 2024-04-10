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

int sz[N], p[N];

int get(int x){
    if(x != p[x])p[x] = get(p[x]);
    return p[x];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int ans = 0, s = 0;

    set <pii> st, st1;

    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        p[i] = i;
        st.insert({1, i});
    }

    int t = 1;

    while(q--){
        int a, b;
        cin >> a >> b;
        if(get(a) == get(b)){
            t++;            
        }else{        
            a = get(a), b = get(b);
            if(st1.find({sz[a], a}) != st1.end()){
                st1.erase({sz[a], a});
                s -= sz[a];
            } else st.erase({sz[a], a});            
            if(st1.find({sz[b], b}) != st1.end()){
                st1.erase({sz[b], b});
                s -= sz[b];
            } else st.erase({sz[b], b});            
            sz[b] += sz[a];
            p[a] = b;
            ans = max(ans, sz[b] - 1);
            st.insert({sz[b], b});
        }        
        while(st1.size() < t){
            if(st.empty()){ 
                break;
            }
            pii xe = *--st.end();
            st.erase(--st.end());
            st1.insert(xe);
            s += xe.fi;
        }
        if(!st.empty()){
            while((--st.end()) -> fi > st1.begin() -> fi){
                pii xe = *st1.begin();
                pii xe1 = *--st.end();
                st1.erase(xe);
                st.erase(xe1);
                s -= xe.fi;
                s += xe1.fi;
                st.insert(xe);
                st1.insert(xe1);
            }
        }
        cout << max(ans, s - 1) << "\n";
    }
    
    return 0;
}