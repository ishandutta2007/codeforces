#include <bits/stdc++.h>

#define ll long long 

#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef bobo
#define bug(x) cerr<<#x<<" is "<<x<<endl
#else
#define bug(x)
#endif
using namespace std;

#define int ll
#define pii pair<ll, ll>
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

struct event{
    ll t; int i; int tp;
    event(ll t, int i, int tp) : t(t),i(i),tp(tp){}
};

struct cmp{
    bool operator () (event a, event b){
        if (a.t!=b.t) return a.t>b.t;
        if (a.tp!=b.tp) return a.tp<b.tp;
        return a.i>b.i;
    }
};


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, p; cin>>n>>p;
    priority_queue<event, vector<event>, cmp> pq;
    vector<int> a(n);
    REP(i,n){
        cin>>a[i];
        pq.push({a[i],i,1});
    }
    queue<pii> q; // time, id
    set <int> iq;
    priority_queue<int, vector<int>, greater<int>  > want;
    vector<int> ans(n);
    int T = 0;
    bool wat = 0;
    while (!pq.empty()){
        event e = pq.top(); pq.pop();
        bug(e.i); bug(e.tp);
        if (iq.size()) bug(*iq.begin());
        T = e.t;
        if (e.tp==1){
            want . push(e.i);
        }else{
            ans[e.i] = e.t; iq.erase(e.i); wat = 0;
        }
        while (!want.empty()){
            if (iq.empty() || want.top()<*iq.begin()) {
                q.push({T,want.top()}); iq.insert(want.top()); 
                bug (want.top() ); want.pop();

            }else break;
        }
        if (wat==0 && !q.empty() ){
            pq.push({T+p, q.front().s, 0});  q.pop(); wat = 1;
        }
        
    }
    REP(i,n){
        cout<<ans[i]<<' ';
    }

}