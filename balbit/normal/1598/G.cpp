#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define int ll
#define y1 zck_is_king
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

const int maxn = 1e6+5;

const ll P = 1e9+87;
const ll P2 = 1e9+9;

//int a[maxn];
ll sufs[maxn]; // suffix sum
ll pw[maxn], pw2[maxn], iv[maxn], iv2[maxn];

vector<int> Z(string S) {
	vector<int> z(SZ(S));
	int l = -1, r = -1;
	REP1(i,SZ(S)-1) {
	    if (i % 100 == 0) bug(i);
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < SZ(S) && S[i + z[i]] == S[z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

vector<int> OZ;

string s,x;
inline ll get(int l, int r) {
//    if (l < 0 || r >= SZ(s)) {
//        return -l-1;
//    }
    return (sufs[l] - sufs[r+1] + P) % P * iv[SZ(s)-r-1] % P;
}
inline ll get2(int l, int r) {
    if (l < 0 || r >= SZ(s)) {
        assert(0);
    }
    return (sufs[l] - sufs[r+1] + P2) * iv[SZ(s)-r-1] % P2;
}

inline int getcom(int pos) {
    assert(pos + SZ(x) + 1< SZ(OZ));
    return OZ[pos + SZ(x) + 1]; // might need to shift one
}
void ANS(int a, int b, int c) {
    ++a; ++b; ++c;
    cout<<a<<' '<<b-1<<endl<<b<<' '<<c<<endl;
    exit(0);
}

ll xp = 0;

inline bool GO(int a, int b, int c, int d) {
    if (a < 0 || d >= SZ(s) || a>b || c>d || b!=c-1) return 0;
    return (get(a,b) + get(c,d)) % P == xp;
}

signed main(){
    IOS();
    clock_t t = clock();
    pw[0] = iv[0] = pw2[0] = 1; // remember to add iv2 if needed
    REP1(i, maxn-1) {
        pw[i] = pw[i-1] * 10 % P;
        iv[i] = inv(pw[i], P);
        pw2[i] = pw2[i-1] * 10 % P2;
    }
     cin>>s;
//    {
//        s = "";
//        REP(i, 400000) s += "3";
//    }
    int n = SZ(s);
    cin>>x;
//    {
//        x = "";
//        REP(i, 200000) x += "6";
//    }
    int X = SZ(x);
    REP(i,X) {
        xp += (ll)(x[i] - '0') * pw[X-i-1] % P;
    }
    xp %= P;
    bug(xp);
    string zstr = x + "#" + s;
    bug("ready");
    OZ = Z(zstr);
    bug("yoink");
    REP(i, SZ(OZ)){
        bug(i, OZ[i]);
    }

    RREP(i,n) {
//        a[i] = s[i] - '0';
        sufs[i] = (sufs[i+1] + (ll)(s[i]-'0') * pw[n-1-i]) % P;
    }
    for (int i = SZ(s)-1; i>0; --i) {
//        if ((clock() - t) > CLOCKS_PER_SEC * 1) {
//            cout<<i<<endl;
//
//            assert(0);
//        }
        if (i + X - 1 < SZ(s)){
            int com = getcom(i); // the right side has length SZ(X)
            for (int L = X - com - 1; L <= X - com; ++L) {
                if (L > 0 && GO(i-L, i-1, i, i+X-1 )) {
                    ANS(i-L, i, i+X-1);
                }
            }
        }
        if (i-X>=0){
            int j = i-X;
            int com = getcom(j);
            for (int L = X - com - 1; L <= X - com; ++L) {
                if (L > 0 && GO(j,i-1, i, i+L-1)) {
                    ANS(j, i, i+L-1);
                }
            }
        }
        if (X > 1 && i-X+1>=0) {
            if (GO(i-X+1, i-1, i, i+X-2)) {
                ANS(i-X+1, i, i+X-2);
            }
        }
    }

    assert(0);
}