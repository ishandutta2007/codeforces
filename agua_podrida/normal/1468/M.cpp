#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define mod 1000000007
#define PI acos(-1.0)

bool portam(pair<vi,int>& a, pair<vi,int>& b) {
    return a.first.size() < b.first.size();
}

bool pertenecen(vi& v, int x, int y){
    int i = 0;
    while(i < v.size() and v[i] != x) i++;
    i++;
    while(i < v.size() and v[i] != y) i++;
    return i < v.size();
}

int repite(vi& v){
    if(v.empty()) return 0;
    int i = 0;
    while(i+1 != v.size() and v[i] != v[i+1]) i++;
    if(i+1 == v.size()) return 0;
    return v[i];
}

void m(){
    int n;
    cin>>n;
    vector<pair<vi,int>> a(n);
    int ki;
    F0(i,n) {
        cin>>ki;
        a[i].first.resize(ki);
        F0(j,ki) cin>>a[i].first[j];
        F0(j,ki) a[i].first[j]++;
        a[i].second = i+1;
    }


    sort(todo(a),portam);
    F0(i,n) sort(todo(a[i].first));

    unordered_set<int> s;
    while(!a.empty() and a.back().first.size() > 320){
        s.clear();
        for(auto ai : a.back().first) s.insert(ai);
        F0(i, (int) a.size()-1){
            int inter = 0;
            for(auto ai : a[i].first) if(s.count(ai)) inter++;
            if(inter >= 2){
                cout<<a[i].second<<' '<<a.back().second<<'\n';
                return;
            }
        }
        a.pop_back();
    }
    if(a.size() <= 1){
        cout<<"-1\n";
        return;
    }

    map<int,vi> perteneceA;
    F0(i,a.size()) {
        F0(j,a[i].first.size()) perteneceA[a[i].first[j]].pb(i);
    }

    vi v;
    for(auto it : perteneceA){
        int x = it.first;
        v.clear();
        for(auto s : it.second){
            for(auto ai : a[s].first) if(ai > x) v.pb(ai);
        }
        sort(todo(v));
        int y = repite(v);
        if(y != 0){
            int i = 0;
            while(!pertenecen(a[i].first,x,y)) i++;
            int j = i+1;
            while(!pertenecen(a[j].first,x,y)) j++;
            cout<<a[i].second<<' '<<a[j].second<<'\n';
            return;
        }
    }

    cout<<"-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) m();
    return 0;
}