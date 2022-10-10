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
// #define endl "\n"

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
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>m>>k;
    vector<vi> a(k,vi(m));
    for(auto &v:a){
        for(auto &x:v)
            cin>>x;
    }

    vi tsum(k),t2sum(k);
    fo(i,k){
        for(auto x:a[i])
        {
            tsum[i]+=x;
            t2sum[i]+=x*x;
        }
    }

    map<lli,lli> dif;
    fo(i,k-1){
        dif[tsum[i+1]-tsum[i]]++;
    }

    lli d=0;
    dif[0]+=0;
    for(auto x:dif){
        if(dif[d]<x.Y)
            d=x.X;
    }

    dbg(dif,d);
    dbg(tsum);
    lli cord=-1;
    for(lli i=1;i+1<k;++i){
        if(tsum[i]-tsum[i-1]!=d){
            cord=i;
            break;
        }
    }

    dbg(cord);
    cout<<cord<<" ";

    auto &cur=a[cord];
    const lli delta = d-(tsum[cord]-tsum[cord-1]);
    lli diff=t2sum[cord-1]+t2sum[cord+1]-2*t2sum[cord];

    for(lli i=1;i+1<k;++i){
        if(i==cord||i-1==cord||i+1==cord)
            continue;
        diff-=t2sum[i-1]+t2sum[i+1]-2*t2sum[i];
        dbg("Hello",t2sum[i-1]+t2sum[i+1]-2*t2sum[i]);
        break;
    }

    dbg(delta,diff);
    dbg(cur);
    fo(i,m){
        diff+=2*cur[i]*cur[i];
        cur[i]+=delta;
        diff-=2*cur[i]*cur[i];
        dbg(i,cur[i],diff);
        if(diff==0){
            cout<<cur[i]<<endl;
            return 0;
        }
        diff+=2*cur[i]*cur[i];
        cur[i]-=delta;
        diff-=2*cur[i]*cur[i];
    }

}   aryanc403();
    return 0;
}