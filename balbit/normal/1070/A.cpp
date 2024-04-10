#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
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
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;


const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"0\n"; exit(0);}

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

const int maxn = 1e6+5;

bool vis[505][5105];

struct nd{
    int m, s;
    string str="";
    nd(int m, int s, string str): m(m),s(s), str(str){}
};

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int D, S; cin>>D>>S;
    queue<nd> q; q.push({0,0,""}); 
    vis[0][0]=1;
    while (!q.empty()){
        nd x = q.front(); q.pop();
        if (x.s>S) continue; 
        if (x.m == 0 && x.s == S){
            cout<<x.str<<'\n'; return 0;
        }
        REP(i,10){
            int newm = (x.m*10+i)%D; int news = x.s+i;
            if (!vis[newm][news]){
                vis[newm][news]=1;
                q.push({newm, news, x.str + (char)(i+'0')});
            }
        }
    }
    cout<<"-1";
}