/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif
namespace std {

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

} // namespace std

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

typedef long long int lli;
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

ii get(ii x){
    lli g=__gcd(x.X,x.Y);
    x.X/=g;
    x.Y/=g;
    return x;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    vii b;
    vector<pair<ii,ii>> a;
    fo(i,n)
    {
        lli xn,xd,yn,yd;
        cin>>xn>>xd>>yn>>yd;
        ii x=get({xn,xd});
        ii y=get({yn,yd});
        a.pb({x,y});
        b.pb(get({y.X*x.Y,y.Y*(x.X+x.Y)}));
        b.pb(get({(y.X+y.Y)*x.Y,y.Y*x.X}));
    }
    dbg(a);
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    dbg(b);

    auto find=[&](ii x){
        return lower_bound(all(b),x)-b.begin();
    };

    const lli m=sz(b);
    vii ea;
    vector<vector<ii>> e(m);
    for(int i=0;i<n;++i){
        auto x=a[i].X,y=a[i].Y;
        auto p1=get({y.X*x.Y,y.Y*(x.X+x.Y)});
        auto p2=get({(y.X+y.Y)*x.Y,y.Y*x.X});
        const lli e1=find(p1),e2=find(p2);
        assert(b[e1]==p1);
        assert(b[e2]==p2);
        e[e1].pb({e2,i});
        e[e2].pb({e1,i});
    }

    vii ans;

    vector<bool> vis(m+n,false),edgeMarked(n,false);
    vi leftover={-1,-1,-1};
    for(int i=0;i<m;++i)
    {
        if(vis[i])
            continue;
        if(e[i].empty())
            continue;
        y_combinator(
                [&](auto self, int u,int p,int pe) -> bool {
                    if(vis[u])
                        return !edgeMarked[pe];
                    dbg("visiting",u);
                    vis[u]=true;
                    ii cur={-1,-1};
                    for(auto x:e[u])
                    {
                        if(x.Y==pe)
                            continue;
                        if(self(x.X,u,x.Y)){
                            if(cur.X==-1)
                                cur=x;
                            else
                            {
                                edgeMarked[cur.Y]=edgeMarked[x.Y]=true;
                                ans.pb({cur.Y,x.Y});
                                cur={-1,-1};
                            }
                        }
                    }

                    if(cur.X==-1)
                        return true;
                    if(p==-1)
                        return false;
                    edgeMarked[cur.Y]=edgeMarked[pe]=true;
                    ans.pb({cur.Y,pe});
                    return false;
                }
            )(i,-1,-1);
    }

    cout<<sz(ans)<<endl;
    for(auto x:ans)
        cout<<x.X+1<<" "<<x.Y+1<<endl;
}   aryanc403();
    return 0;
}