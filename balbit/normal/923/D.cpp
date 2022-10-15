#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


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

const int maxn = 1e5+5;

int p[maxn], q[maxn];
int ta[maxn], sa[maxn];

signed main(){
    IOS();
    string s,t; cin>>s>>t;
    int n = s.length(), m = t.length();
    for (int i = 0; i<n; ++i) {
        p[i+1] = s[i] != 'A';
        p[i+1] += p[i];
        if (s[i] == 'A') {
            sa[i+1] = sa[i] + 1;
        }else{
            sa[i+1] = 0;
        }
    }
    for (int i = 0; i<m; ++i) {
        q[i+1] = t[i] != 'A';
        q[i+1] += q[i];
        if (t[i] == 'A') {
            ta[i+1] = ta[i] + 1;
        }else{
            ta[i+1] = 0;
        }
        bug(ta[i+1]);
    }
    int Q; cin>>Q;
    while (Q--) {
        int l,r,L,R;
        cin>>l>>r>>L>>R;
        int a = p[r]-p[l-1], b = q[R]-q[L-1];
        bug(a,b);
        if ((a%2 != b%2) || a>b) cout<<0;
        else {
            int SA = min(sa[r], r-l+1);
            int TA = min(ta[R], R-L+1);
            bug(SA, TA);
            if (((a==b) && (SA%3 != TA % 3)) || (SA < TA) ) cout<<0;
            else{
                if (a==0 && b!=0 && (SA-1<TA)) cout<<0;
                else cout<<1;
            }
        }
    }
}