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

const int maxn = 1e6+5;

bool F[5003][5003];
int nst[5003];

signed main(){
    IOS();
    string s; cin>>s; int n = s.length();
    int k; cin>>k;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<=i; ++j) {
            F[i][j] = 1;
        }
    }
    vector<int> nofc(26);
    for (int d = 0; d<n; ++d) {
        for (int i = 0; i<n; ++i) {
            int j = i+d; if (j >=n) break;
            if (s[i] == s[j] && (i+2>j-2 || F[i+2][j-2])) {
                F[i][j] = 1;
                nst[i]++;
                nofc[s[i]-'a'] ++;
            }
        }
    }
    vector<int> poss;
    vector<int> num;
    vector<int> re;
    for (int i = 0; i<26; ++i) {
        if (nofc[i] >= k) {
            re.pb(i);
            for (int j = 0; j<n; ++j) {
                if (s[j]-'a' == i) {
                    poss.pb(j);
                    num.pb(nst[j]);
                }
            }
            break;
        }else{
            k-=nofc[i];
        }
    }
    for (int d = 0; d<1000000; ++d) {
        bug(d, re.back(), k);
        int notake = 0;
        for (int i =0; i<SZ(poss); ++i) {
            if (poss[i] != -1) {
                bug(poss[i]);
                if (poss[i] + d < n && F[poss[i]][poss[i]+d]) {

                    notake++;
                    num[i] -- ;
                    bug(poss[i], num[i]);
                }
            }
        }
        bug(notake);
        if (notake >= k) {
            break;
        }
        k -= notake;
        vector<int> nxt(26);
        for (int i =0; i<SZ(poss); ++i) {
            if (poss[i] != -1) {
                if (poss[i] + d +1 < n) {
                    nxt[s[poss[i]+d+1]-'a'] += num[i];
                }else poss[i] = -1;
            }
        }
        for (int i = 0; i<26; ++i) {
            if (nxt[i] >= k) {
                re.pb(i); break;
            }else{
                k -= nxt[i];
            }
        }
        for (int i = 0; i<SZ(poss); ++i) {
            if (poss[i] !=-1) {
                if (s[poss[i]+d+1] - 'a' != re.back()) {
                    poss[i] = -1;
                }
            }
        }
    }
    for (int x : re) cout<<(char)('a'+x);
}