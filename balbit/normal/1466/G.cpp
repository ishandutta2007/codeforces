#include <bits/stdc++.h>
//#undef BALBIT
using namespace std;
#define ll long long
#define int ll
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
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e5+5;

int z[maxn*4];
string mat = "";

int finL, finR;

vector<int> Z(string S) {
//	vector<int> z(SZ(S));
//    S = S;
	int l = finL, r = finR;
	int msz = SZ(mat)-1;
	for (char c : S) mat.pb(c);
	for (int i = msz+1; i<SZ(mat); ++i){
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < SZ(mat) && mat[i + z[i]] == mat[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
    bug(S, msz+1, z[msz+1]);
	REP(i,SZ(S)) mat.pop_back();
	vector<int> re;
	for (int i = 1; i<=SZ(S); ++i) {
        re.pb(z[i+msz]);
	}
	return re;
//	return z;
}

ll nof[maxn][26];

signed main(){
    IOS();
//    bug(__lg(1), __lg(2), __lg(3), __lg(4), __lg(5));
    int m,q; cin>>m>>q;
    string s0, t; cin>>s0>>t;
    REP(i,SZ(t)) {
        if (i) {
            REP(j,26) nof[i][j] += nof[i-1][j];
        }
        (nof[i][t[i]-'a'] += inv(mpow(2,i)))%=mod;
    }
    for (int i = 0; i<m; ++i) {
        if (SZ(mat) < 100000) {
            mat = mat+t[i]+mat;
        }
    }
    while (SZ(mat) > 100000) mat.pop_back();
    mat.pb('#');
    bug(mat);
    {
        int l = -1, r = -1;
        REP1(i,SZ(mat)-1) {
            z[i] = i >= r ? 0 : min(r - i, z[i - l]);
            while (i + z[i] < SZ(mat) && mat[i + z[i]] == mat[z[i]])
                z[i]++;
            if (i + z[i] > r)
                l = i, r = i + z[i];
        }
        finL = l; finR = r;
    }
//    REP(i, SZ(mat)+1) {
//        cout<<z[i]<<' ';
//    }
//    cout<<endl;
    REP(hohoho,q) {
        int k; string os; cin>>k>>os; --k;
        int n = SZ(os);
        ll ans = 0;
        for (int at = 0; at <= SZ(s0); ++at) {
            bool ok = 1;
            string s = "";
            for (int i = 0; i<n; ++i) {
                int j = (i+at) % (SZ(s0)+1);
                if (j != SZ(s0) && os[i] != s0[j]) {
                    ok = 0; break;
                }
                if (j == SZ(s0)) {
                    s.pb(os[i]);
                }
            }
            if (ok) {
                bug(s);
                if (s == "") {
                    ans += mpow(2,k+1); ans %= mod; continue;
                }
                if (k == -1) continue;
                vector<int> v2 = Z(s);
                reverse(ALL(s));
                vector<int> v1 = Z(s);
                reverse(ALL(s));
                reverse(ALL(v1));
//                REP(i,SZ(s)) {
//                    cout<<v1[i]<<' ';
//                }
//                cout<<endl;
//                REP(i,SZ(s)) {
//                    cout<<v2[i]<<' ';
//                }
//                cout<<endl;
                ll re = 0;
                REP(i,SZ(s)) {
                    if (i == 1) bug(v1[i-1]);
                    if (i==0 || v1[i-1] == i) {
                        if (i==SZ(s)-1 || v2[i+1] == (SZ(s) - i - 1)) {
                            int dst = (max(i, SZ(s)-i-1));
                            if(dst==0) dst=-1;
                            else dst = __lg(dst);
                            // I need to use stuff > dst in t
                            if (dst >= k) continue;
                            ll tmp = (nof[k][s[i] - 'a'] - (dst==-1?0ll:nof[dst][s[i]-'a']));
                            if (tmp < 0) tmp += mod;
                            ll toto = mpow(2,k) * tmp % mod;
                            bug(toto, dst, tmp, k, s[i]);
                            re += toto;
                        }
                    }
                }
                ans += re; ans %= mod;
            }
        }
        cout<<ans<<endl;
    }

}

/*
4 1
aba
bbac
3 aa


2 1
z
ab
2 bza

*/