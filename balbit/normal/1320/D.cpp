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
//#undef BALBIT
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+87;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 2e5+5;
#ifndef BALBIT
const ll B = 59;
#else
const ll B = 100;
#endif
int pf0[maxn], fr[maxn], bk[maxn];
ll pB[maxn], ipB[maxn], hv[maxn]; // hash value only applies for 0 (?)
 // prefix, front 0, back 0
bool s[maxn];


ll Ha(int a, int b) {
    int x = fr[a], y = bk[b];
//    bug(hv[x],hv[y]);
    int n0 = pf0[b+1]-pf0[a];
    bug(n0,(((b-y) % 2)+1) * pB[n0]);
    ll re = (hv[y] - hv[x]);
    if (re < 0) re += mod;
    bug(re, ipB[pf0[x+1]-1]);
    re = re * ipB[pf0[x+1]-1] % mod;
    bug(re);
    re = (re + (((x-a) % 2)+1));
    re = (re + (((b-y) % 2)+1) * pB[n0])%mod;
    bug(re);
    return re;
}
/*
6
010101
5
1 1 3

*/

signed main(){
    IOS();
    pB[0] = ipB[0] = 1;
    for (int i = 1; i<maxn; i++) {
        pB[i] = pB[i-1] * B % mod;
        ipB[i] = inv(pB[i]);
    }
//    bug(pB[1], ipB[1]);
    int n; cin>>n;
    for (int i = 0; i<n; i++) {
        char x; cin>>x;
        s[i] = x=='1';
    }
    for (int i = 0; i<n; i++) {
        pf0[i+1] = pf0[i];
        if (s[i] == 0) {
            pf0[i+1]++;
        }
    }
    int prv = -1;
    for (int i = 0; i<n; i++) {
        if (s[i] == 0) {
            if (prv != -1) {
                hv[i] = hv[prv] + pB[pf0[i+1]-1] * (((i-prv+1) % 2)+1);
                hv[i] %= mod;
                bug(i, hv[i]);
            }
            prv = i;
        }
        bk[i] = prv;
    }
    prv = n;
    for (int i = n-1; i>=0; i--) {
        if (s[i] == 0) {
            prv = i;
        }
        fr[i] = prv;
    }
    int q; cin>>q;
    while (q--) {
        int a,b,t; cin>>a>>b>>t;
        --a; --b;
        int ae = a+t-1, be = b+t-1;
        int A0 = pf0[ae+1]-pf0[a], B0 = pf0[be+1]-pf0[b];
        bug(A0,B0);
        if (A0 != B0) {
            cout<<"No"<<endl; continue;
        }
        if (A0 == B0 && A0 == 0) {
            cout<<"Yes"<<endl; continue;
        }
        if (Ha(a,ae) == Ha(b,be)) {
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}