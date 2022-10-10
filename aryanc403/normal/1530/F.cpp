/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

// typedef long long int lli;
typedef int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Math/ModularArithmetic.cpp
template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;

	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

using mint = modBase<31607>;
using vm=vector<mint>;

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;
// https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Math/BitwiseTransform.cpp
template<const char ch, class T>
void FWHT(std::vector<T> &a, const bool inv = false) {
	int n = (int) a.size();
	for(int len = 1; len < n; len += len) {
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				auto u = a[i + j], v = a[i + j + len];
				if(ch == '&') {
					if(!inv) {
						a[i + j] += a[i + j + len];
					} else {
						a[i + j] -= a[i + j + len];
					}
				}
			}
		}
	}
}

void andConvo(vm &a,vm &b){
    FWHT<'&'>(b);
    for(lli i=0;i<sz(a);++i)
        a[i]*=b[i];
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    const mint inv10000=mint(1)/10000;
    lli n;
    cin>>n;
    vector<vm> a(n,vm(n));
    for(auto &v:a)
    for(auto &x:v){
        // lli in;
        cin>>x;
        x*=inv10000;
        // x=mint(1)-x;
    }
    dbg(a);
    mint ans=0;
    const lli lim=4LL<<n,fd=(1LL<<n),rd=2LL<<n;
    vm dp(lim);
    dp[lim-1]=1;
    FWHT<'&'>(dp);
    mint sum=1;
    vm dp2(lim);
    vi cmsk(lim);
    vm prod(lim);
    vi masks(n),onBit(1<<n,-1);
    for(lli i=0;i<n;++i)
        onBit[1<<i]=i;
    for(lli row=0;row<n;++row){
        auto &cur=a[row];
        mint allProd=1;
        for(auto &x:cur){
            allProd*=x;
            x=(mint(1)-x)/x;
        }
        for(auto &x:dp2)
            x=0;
        for(lli j=0;j<n;++j){
            lli msk=(lim-1);
            msk^=(1LL<<j);
            if(row==j)
                msk^=fd;
            if(row+j==n-1)
                msk^=rd;
            masks[j]=msk;
            // dbg(row,j,bitset<6>(msk));
        }

        cmsk[0]=lim|(lim-1);
        prod[0]=allProd;

        for(lli msk=1;msk<(1<<n);++msk){
            const int i=msk&(-msk);
            dbg(i,bitset<30>(msk));
            const int j=onBit[i];
            assert(j!=-1);
            cmsk[msk]=cmsk[msk^i]&masks[j];
            prod[msk]=prod[msk^i]*cur[j];
        }

        for(lli msk=0;msk<(1<<n);++msk){
            const auto &p=prod[msk];
            if(cmsk[msk]&lim){
                ans+=sum*p;
                sum*=mint(1)-p;
            } else {
                dp2[cmsk[msk]]+=p;
            }
        }
        andConvo(dp,dp2);
    }
    dbg(dp);
    FWHT<'&'>(dp,true);
    for(lli i=1;i<lim;++i)
        ans+=dp[i];
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}