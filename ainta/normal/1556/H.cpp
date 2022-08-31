#include <bits/stdc++.h>
using namespace std;
 
 
namespace Rec{
    template<class Fun>
    class y_combinator_result {
        Fun fun_;
    public:
        template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
        template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
    };
 
    template<class Fun>
    decltype(auto) y_combinator(Fun &&fun) {
        return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
    }
}
 
 
//fast IO by yosupo
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();            
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(vector<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
 
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }
 
    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }
 
  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const vector<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
 
 
using ll=long long;
//#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pii=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif
 
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
 
template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	return os<<vc<t>(all(a));
}
 
template<int i,class T>
void print_tuple(ostream&,const T&){
}
 
template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}
 
template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}
 
template<class t>
void print(t x,int suc=1){
	cout<<x;
	if(suc==1)
		cout<<"\n";
	if(suc==2)
		cout<<" ";
}
 
ll read(){
	ll i;
	cin>>i;
	return i;
}
 
vi readvi(int n,int off=0){
	vi v(n);
	rep(i,n)v[i]=read()+off;
	return v;
}
 
template<class T>
void print(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print(v[i],i==int(v.size())-1?suc:2);
}
 
string readString(){
	string s;
	cin>>s;
	return s;
}
 
template<class T>
T sq(const T& t){
	return t*t;
}
 
//#define CAPITAL
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
}
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
}
 
constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}
 
const ll infLL=LLONG_MAX/3;
 
#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif
 
int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}
 
template<class t>
bool inc(t a,t b,t c){
	return a<=b&&b<=c;
}
 
template<class t> void mkuni(vc<t>&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}
 
ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}
 
template<class t>
int lwb(const vc<t>&v,const t&a){
	return lower_bound(all(v),a)-v.bg;
}
 
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;
 
 
int w[60][60], ori[60][60];
 
const int MAXN = 350;
 
struct disj{
	int pa[MAXN], comp;
	void init(int n){
		iota(pa, pa + n + 1, 0);
		comp = n;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		comp--;
		pa[q] = p; return 1;
	}
}uf;
 
namespace spfa{
	vector<pii> gph[MAXN];
	int dist[MAXN], par[MAXN];
	void clear(){
		for(int i=0; i<MAXN; i++) gph[i].clear();
	}
	void add_edge(int s, int e, int x){
		gph[s].emplace_back(x, e);
	}
	vector<int> find_path(int s, int e){
		memset(dist, 0x3f, sizeof(dist));
		bool inq[MAXN] = {};
		dist[s] = 0; 
		queue<int> que; que.push(s); inq[s] = 1;
		while(si(que)){
			int x = que.front();
			que.pop();
			inq[x] = 0;
			for(auto &i : gph[x]){
				if(dist[i.second] > dist[x] + i.first){
					dist[i.second] = dist[x] + i.first;
					par[i.second] = x;
					if(!inq[i.second]){
						inq[i.second] = 1;
						que.push(i.second);
					}
				}
			}
		}
		if(dist[e] > 1e8) return {};
		vector<int> v;
		for(int j=e; j!=s; j=par[j]){
			v.push_back(par[j]);
		}
		reverse(v.begin(), v.end());
		return v;
	}
}
 
int n, m;
bool indep[MAXN];
 
 
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	Scanner sc(stdin);
	Printer pr(stdout);
 
    int n, K;
    sc.read(n,K);
    vi Deg(n+1), ODeg(n+1);
    rng(i,1,K)sc.read(Deg[i]);
 
    rng(i,1,n){
        rng(j,i+1,n){
            sc.read(w[i][j]);
            w[j][i] = w[i][j];
        }
    }
    rng(i,1,n)rng(j,1,n)ori[i][j]=w[i][j];
 
    vc<pii>Ed, E;
 
    rng(i,1,K){
        rng(j,i+1,K){
            Ed.pb({i,j});
        }
    }
    rng(i,1,n){
        rng(j,i+1,n){
            if(j>K) E.pb({i,j});
        }
    }
 
    sort(all(E), [](pii a, pii b)-> bool {
        return w[a.fi][a.se] < w[b.fi][b.se];
    });
 
    uf.init(n);
    vc<pii> EE;
    for(auto [a,b] : E){
        if(a>K && b>K){
            if(uf.uni(a,b)){
                EE.pb({a,b});
            }
        }
        else{
            EE.pb({a,b});
        }
    }
    E = EE;
 
    int m = si(E);
 
    int M = si(Ed);
 
    int res = 1e9;
 
    rep(i,(1<<M)){
        vc<pii>Z;
        vi ODeg = Deg;
        rep(j,M){
            if((i>>j)&1)Z.pb(Ed[j]);
        }
        int Sum = 0;
        int ck=0;
        uf.init(n);
        for(auto [a,b]: Z){
            Sum += w[a][b];
            Deg[a]--,Deg[b]--;
            if(!uf.uni(a,b))ck=1;
        }
        rng(i,1,K){
            //printf("o %d\n",Deg[i]);
            if(Deg[i]<0)ck=1;
        }
        Deg = ODeg;
        if(ck)continue;
 
        rep(i,m)indep[i] = 0;
 
        int cnt = si(Z);
 
        //printf("! %d %d\n",cnt,Sum);
        while(1){
            auto Cost = [&](pii a) -> int{
                return w[a.fi][a.se];
            };
            auto add_edge = [&](int s, int e){
                int cost;
                if(e>=m) cost = 0;
                else cost = (indep[e] ? -Cost(E[e]) : Cost(E[e]));
                spfa::add_edge(s, e, cost * 1024 + 1);
            };
        	spfa::clear();

            
            uf.init(n);
            for(auto [a,b]: Z){
                uf.uni(a,b);
            }
            rep(i,m){
                if(indep[i]){
                    uf.uni(E[i].fi, E[i].se);
                }
            }
            int ss = Sum;
            rep(i,m){
                if(!indep[i]){
                    if(uf.uni(E[i].fi,E[i].se)) ss += Cost(E[i]);
                }
            }
            if(ss>res)break;


            for(int i=0; i<m; i++){
                uf.init(n);
                vi DD = Deg;
                for(auto [a,b]: Z){
                    uf.uni(a,b);
                    DD[a]--,DD[b]--;
                }
                for(int j=0; j<m; j++){
                    if(i!=j && indep[j]){
                        uf.uni(E[j].fi, E[j].se);
                        DD[E[j].fi]--;
                        DD[E[j].se]--;
                    }
                }
                if(!indep[i]){
                    if(uf.find(E[i].fi) != uf.find(E[i].se)){
                        add_edge(m, i);
                    }
 
                    auto [a,b] = E[i];
                    if((a>K || DD[a]>0) && (b>K || DD[b]>0)){
                        add_edge(i, m+1);
                    }
 
 
                }
                for(int j=0; j<m; j++){
                    if(!indep[j] && uf.find(E[j].fi) != uf.find(E[j].se)){
                        add_edge(i, j);
                    }
                }
                for(int j=0; j<m; j++){
                    if(!indep[j]){
                        auto [a,b] = E[j];
                        if((a>K || DD[a]>0) && (b>K || DD[b]>0)){
                            add_edge(j, i);
                        }
                    }
                }
            }
            //puts("?");
            auto ans = spfa::find_path(m, m+1);
            //printf("%d\n",si(ans));
            if(si(ans) == 0) break;
            int ret = (spfa::dist[m+1] >> 10);
            for(int i=1; i<si(ans); i++){
                //printf("rev %d\n",ans[i]);
                indep[ans[i]] ^= 1;
            }
            Sum += ret;
            cnt++;
            //printf("%d %d %d\n",cnt,ret,Sum);
        }
        if(cnt == n-1){
            res = min(res,Sum);
        }
    }
    printf("%d\n",res);
 
}