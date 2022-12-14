 #include <bits/stdc++.h>

 #pragma GCC optimize("-O3")

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
const int N = 1e6 + 100;
const int inf = 1e9;
const int con = 64;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int a[N], b[N];

ll solve(int l, int r){
    if(l == r){
        return 1;        
    }
    int m = (l + r) >> 1;
    ll ans = solve(l, m) + solve(m + 1, r);
    ll rofl = ans;

    vector <int> al, ar;
    vector <int> _min_p;
    vector <int> sum_min(con), sum_max(con);
    int _minl, _maxl, _minr, _maxr;
    int ukl, ukl1;

    for(int i = m + 1; i <= r; i++) ar.p_b(a[i]);
    for(int i = m; i >= l; i--) al.p_b(a[i]);

    //
    _minl = _maxl = al[0];
    _minr = _maxr = ar[0];

    ukl = 0;

    for(auto i : ar){
        _minr = min(_minr, i);
        _maxr = max(_maxr, i);
        while(ukl < al.size() && min(_minl, al[ukl]) > _minr && max(_maxl, al[ukl]) < _maxr){
            _minl = min(_minl, al[ukl]);
            _maxl = max(_maxl, al[ukl]);
            ukl++;
        }
        if(b[_minr] == b[_maxr])ans += ukl;        
    }

    
    _min_p.resize(al.size());

    _minl = al[0];
    for(int i = 0; i < al.size(); i++){
        _minl = min(_minl, al[i]);
        _min_p[i] = _minl;                        
    }

    ukl1 = 0;
    ukl = 0;
    
    _maxl = al[0];
    _minl = al[0];
    _minr = _maxr = ar[0];

    fill(all(sum_min), 0);
    fill(all(sum_max), 0);


    for(auto i : ar){
        _minr = min(_minr, i);
        _maxr = max(_maxr, i);
        while(ukl < al.size() && _minl > _minr){   
            sum_min[b[_min_p[ukl]]]++;                 
            ukl++;          
            if(ukl == al.size()) break;  
            _minl = min(_minl, al[ukl]);
        }

        while(ukl1 < al.size() && _maxl < _maxr){                    
            sum_max[b[_min_p[ukl1]]]++;                 
            ukl1++;
            if(ukl1 == al.size()) break;
            _maxl = max(_maxl, al[ukl1]);
        }

        if(ukl == al.size()){
            break;
        }            
        
        if(ukl < ukl1){
            if(ukl1 > 0){
                ans += sum_max[b[_maxr]];
            }
            if(ukl > 0){
                ans -= sum_min[b[_maxr]];                
            }
        }        
    }

    //

    swap(al, ar);

    //
    _minl = _maxl = al[0];
    _minr = _maxr = ar[0];

    ukl = 0;

    for(auto i : ar){
        _minr = min(_minr, i);
        _maxr = max(_maxr, i);
        while(ukl < al.size() && min(_minl, al[ukl]) > _minr && max(_maxl, al[ukl]) < _maxr){
            _minl = min(_minl, al[ukl]);
            _maxl = max(_maxl, al[ukl]);
            ukl++;
        }
        if(b[_minr] == b[_maxr])ans += ukl;        
    }

    
    _min_p.resize(al.size());

    _minl = al[0];
    for(int i = 0; i < al.size(); i++){
        _minl = min(_minl, al[i]);
        _min_p[i] = _minl;                        
    }

    ukl1 = 0;
    ukl = 0;
    
    _maxl = al[0];
    _minl = al[0];
    _minr = _maxr = ar[0];

    fill(all(sum_min), 0);
    fill(all(sum_max), 0);


    for(auto i : ar){
        _minr = min(_minr, i);
        _maxr = max(_maxr, i);
        while(ukl < al.size() && _minl > _minr){   
            sum_min[b[_min_p[ukl]]]++;                 
            ukl++;          
            if(ukl == al.size()) break;  
            _minl = min(_minl, al[ukl]);
        }

        while(ukl1 < al.size() && _maxl < _maxr){                    
            sum_max[b[_min_p[ukl1]]]++;                 
            ukl1++;
            if(ukl1 == al.size()) break;
            _maxl = max(_maxl, al[ukl1]);
        }

        if(ukl == al.size()){
            break;
        }            
        
        if(ukl < ukl1){
            if(ukl1 > 0){
                ans += sum_max[b[_maxr]];
            }
            if(ukl > 0){
                ans -= sum_min[b[_maxr]];                
            }
        }        
    }
    
    //

    

    return ans;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <pll> c;
    vector <ll> d(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> d[i];
        c.p_b({d[i], i});
    }

    sort(all(c));

    for(int i = 0; i < n; i++){
        a[c[i].second] = i + 1;
    }

    for(int i = 1; i <= n; i++){
        ll x = d[i];
        b[a[i]] = 0;
        while(x){
            b[a[i]] += x & 1;
            x >>= 1;
        }                
    }
    
    cout << solve(1, n) << "\n";
    
    return 0;
}