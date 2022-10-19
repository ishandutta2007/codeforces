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
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

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
#define eps 0.000000000001
#define mod 998244353

struct Vertex {
    unordered_map<int,int> next,go;
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int exit = -1;
    multiset<int> val;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
    }
};

vector<Vertex> t(1);

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next.count(c) == 0) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].val.insert(0);
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go.count(c) == 0) {
        if (t[v].next.count(c))
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int get_exit(int v){
    if(v == 0) return 0;
    if(t[v].exit == -1){
        if(t[v].leaf) t[v].exit = v;
        else t[v].exit = get_exit(get_link(v));
    }
    return t[v].exit;
}

void g(){
    int n,m;
    cin>>n>>m;
    string s;
    vi pos(n+1);
    vi val(n+1);
    F1(i,n) {
        cin>>s;
        pos[i] = add_string(s);
    }
    int type,i,x;
    string q;
    while(m--){
        cin>>type;
        if(type == 1){
            cin>>i>>x;
            int v = pos[i];
            t[v].val.erase(t[v].val.find(val[i]));
            val[i] = x;
            t[v].val.insert(x);
        }
        else {
            cin>>q;
            int node = 0;
            int res = -1;
            F0(j,q.size()) {
                node = go(node,q[j]);
                int v = get_exit(node);
                while(v){
                    maxi(res,*t[v].val.rbegin());
                    v = get_exit(get_link(v));
                }
            }
            cout<<res<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    g();
    return 0;
}