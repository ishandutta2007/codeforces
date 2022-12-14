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
const int N = 2e5;
const ll inf = 1e16;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool intersect(pii a, pii b){
    return (max(a.fi, b.fi) <= min(a.se, b.se));
}

bool check(vector <int> &a, int k) {    
    unordered_map <int, pii> mp;
    int n = a.size();
    for(int i = 0; i < n; i++){
        int l, r;
        l = max(0, i - k + 1), r = min(n - k, i);
        int le, ri;
        le = i - r + 1;
        ri = i - l + 1;        
        if(mp.find(a[i]) != mp.end()){
            if(intersect(mp[a[i]], {le, ri})) return true;
        }
        mp[a[i]] = {le, ri};
        
    }
    return false;
}

void solve(){
    int n;
    cin >> n;

    vector <int> a(n);

    for(auto &i : a) cin >> i;  

    int l, r;    
    l = 0, r = n - 1;

    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(check(a, mid)) l = mid;
        else r = mid - 1;
    }

    if(!l) l = -1;

    cout << l << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }    
    
    return 0;
}