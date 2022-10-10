/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#ifdef ARYANC403
    #include "/home/aryan/codes/PastCodes/template/header.h"
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<iostream>
    #include<bits/stdc++.h>
    #define dbg(args...)
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

const lli mod = 998244353L;
const lli N = 26;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a,b;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

vi input()
{
    lli i;
    vi a;
    lli g=0,in;
    fo(i,n)
    {
        cin>>in;
        if(in==0)
            continue;
        if(g*in>0)
            a.back()+=in;
        else
        {
            a.pb(in);
            if(in>0)
                g=1;
            else
                g=-1;
        }
    }
    if(a.empty())
    {
        cout<<"1 1"<<endl;
        exit(0);
    }
    return a;
}

lli po(lli a,lli n)
{
    if(n==0)
        return 1;
    if(n%2)
        return (a*po(a,n-1))%mod;
    return po(a*a%mod,n/2);
}

vi inv(N+3);

lli solve(vi b,const lli st,const lli ed)
{
    b.pb(st);
    sort(all(b));
    b.erase(unique(all(b)),b.end());

    const lli n=sz(b);
    auto gt=[&](const lli v){
        return upper_bound(all(b),v)-1-b.begin();
    };
    vector<vi> polygons(n,vi(N,0));
    assert(b[gt(st)]==st);
    assert(b[gt(0)]==0);
    polygons[gt(st)][0]=1;
    if(st==-1)
        polygons[gt(0)][0]=1;
    for(lli j=0;j+1<n;++j)
        polygons[j].resize(min(N,b[j+1]-b[j]+1));

    auto interpolate=[](vi c,lli x)
    {
        const lli n=sz(c);
        // dbg(c,n,x);
        if(0<=x&&x<n)
            return c[x];
        lli p=1;
        for(lli i=0;i<n;++i)
        {
            // dbg(p);
            c[i]=(c[i]*p)%mod;
            p=(p*inv[i+1])%mod;
            p=(p*((x-i)%mod))%mod;
        }

        p=1;
        for(lli i=n-1;i>=0;--i)
        {
            // dbg(p);
            c[i]=(c[i]*p)%mod;
            p=(-p*inv[n-i])%mod;
            p=(p*((x-i)%mod))%mod;
        }

        lli val=0;
        for(auto x:c)
            val+=x;
        val%=mod;
        val+=mod;
        val%=mod;
        dbg("Ht",c,val,x);
        return val;
    };

    auto eval=[&](lli x)
    {
        const lli pos=gt(x);
        return interpolate(polygons[pos],x-b[pos]);
    };

    // dbg(interpolate({2,4,8,14},-2));
    // dbg(b,eval(st),eval(0));
    lli x=0;
    for(auto gp:a)
    {
        if(gp==0)
            continue;
        lli l,r;
        ii fac;
        if(gp<0)
        {
            l=x+gp,r=x-1;
            fac={0,1};
        }
        else
        {
            l=x+1,r=x+gp;
            fac={1,0};
        }
        dbg(l,r);
        lli nxtol=eval(l-1),nxtne=eval(l-1);
        for(lli i=0;i+1<n;++i)
        {
            // dbg(l,r,b[i],b[i+1]-1)
            if(l>=b[i+1]||r<b[i])
                continue;
            dbg("ct",l,r,b[i],b[i+1]-1,nxtne,nxtol);
            lli ol=nxtol,ne=nxtne,tp;
            nxtol=eval(b[i+1]-1);
            auto &cur=polygons[i];
            for(lli j=0;j<sz(cur);++j)
            {
                // dbg(j,sz(cur));
                tp=cur[j];
                cur[j]=(cur[j]+fac.X*ne+fac.Y*ol)%mod;
                ne=cur[j];
                ol=tp;
            }
            dbg(cur,b[i+1]-1,eval(b[i+1]-1));
            nxtne=eval(b[i+1]-1);
        }
        dbg("Hello");
        x+=gp;
    }
    // dbg(ed,eval(ed));
    return eval(ed);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    lli len=1,l=0,mn=0,cnt=0;
    for(lli i=1;i<N+3;++i)
        inv[i]=po(i,mod-2);
    b.pb(0);
    b.pb(-1);
    b.pb(1);
    vi cd;
    cd.pb(0);
    a=input();
    for(auto in:a)
    {
        cin>>in;
        cnt+=in;
        b.pb(cnt+1);
        b.pb(cnt);
        b.pb(cnt-1);
        cd.pb(cnt);
        if(len<cnt-mn+1)
        {
            len=cnt-mn+1;
            l=mn;
        }
        mn=min(mn,cnt);
    }
    dbg(len,l);
    b.pb(-INF);
    b.pb(INF);
    cout<<len<<" ";

    if(len==1)
    {
        lli ans=1;
        for(auto x:a)
            ans+=-x;
        cout<<ans%mod<<endl;
        return 0;
    }

    sort(all(b));
    b.erase(unique(all(b)),b.end());

    sort(all(cd));
    cd.erase(unique(all(cd)),cd.end());

    lli ans=0;
    for(auto x:cd)
        ans+=solve(b,x-1,x+len-1);
    ans%=mod;
    ans+=mod;
    ans%=mod;

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}