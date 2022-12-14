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

vector <int> v[N];
vector <int> o;
int pr[N];

void dfs(int x, int p = 0){
    pr[x] = p;
    for(auto to : v[x])if(to != p){
        dfs(to, x);
    }
    o.p_b(x);
}

int ask(vector <int> v){
    if(v.size() < 2){
        return -1;
    }
    cout << "? " << v.size();
    for(auto i : v){
        cout << " " << i;
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main(){

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].p_b(b);
        v[b].p_b(a);
    }

    vector <int> vc;

    int mx = 0;

    for(int i = 1; i <= n; i++){
        vc.p_b(i);
    }
    
    dfs(1);

    mx = ask(vc);

    int l = 1, r = n - 1;

    while(l < r){
        int mid = (l + r + 1) >> 1;
        vc.clear();
        for(int i = mid - 1; i < o.size(); i++){
            vc.p_b(o[i]);
        }
        if(ask(vc) < mx){
            r = mid - 1;
        }else{
            l = mid;
        }
    }

    cout << "! " << o[l - 1] << " " << pr[o[l - 1]] << endl;

    return 0;
}