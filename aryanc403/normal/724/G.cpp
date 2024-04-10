/*
  Warn - Don't change next line else you will get WA verdict. Online Judge is configured to give WA if next line is not present.
  "An ideal problem has no test data."
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
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

clock_t time_p=clock();
void aryanc403()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

#ifdef ARYANC403
#define dbg(...) { cerr<<"[ "; __aryanc403__(#__VA_ARGS__, __VA_ARGS__);}
#undef endl
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const pair<Arg1,Arg2> &x) {
    return out<<"("<<x.X<<","<<x.Y<<")";
}

template <typename Arg1>
ostream& operator << (ostream& out, const vector<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
ostream& operator << (ostream& out, const set<Arg1> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
    out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}

template <typename Arg1>
void __aryanc403__(const string name, Arg1&& arg1){
	cerr << name << " : " << arg1 << " ] " << endl;
}

template <typename Arg1, typename... Args>
void __aryanc403__(const string names, Arg1&& arg1, Args&&... args){
	const string name = names.substr(0,names.find(','));
	cerr<<name<<" : "<<arg1<<" | ";
	__aryanc403__(names.substr(1+(int)name.size()), args...);
}

#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || a.X==b.X && a.Y <= b.Y);   }};

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
const lli maxN = 100000L;
const lli me = 63L;

// Credits @tfg
//https://codeforces.com/contest/1100/submission/48339644

struct Gauss {
	lli table[me];

	Gauss() {
		for(lli i = 0; i < me; i++) {
			table[i] = 0;
		}
	}

	lli size() {
		lli ans = 0;
		for(lli i = 0; i < me; i++) {
			if(table[i]) ans++;
		}
		return ans;
	}

	bool can(lli x) {
		for(lli i = me-1; i >= 0; i--) {
			x = std::min(x, x ^ table[i]);
		}
		return x == 0;
	}

	void add(lli x) {
		for(lli i = me-1; i >= 0 && x; i--) {
			if(table[i] == 0) {
				table[i] = x;
				x = 0;
			} else {
				x = std::min(x, x ^ table[i]);
			}
		}
	}

	lli best() {
		lli x = 0;
		for(lli i = me-1; i >= 0; i--) {
			x = std::max(x, x ^ table[i]);
		}
		return x;
	}
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,w,ans;
    string s;
    vii e[maxN+5];
    vector<pair<lli,ii>> b[maxN+5];
    lli a[maxN+5],id[maxN+5];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli root(lli n)
{
    if(n==id[n])
        return n;
    return id[n]=root(id[n]);
}

void merge1(lli u,lli v)
{
    if((lli)b[u].size()<(lli)b[v].size())
        swap(u,v);
    for(auto x:b[v])
        b[u].pb(x);
    id[v]=u;
    b[v].clear();
}

Gauss aa;
lli N,NN;

void dfs1(lli u,lli p,lli c)
{
    a[u]=c;
    for(auto x:e[u])
        if(x.X!=p)
            dfs1(x.X,u,c^x.Y);
}

// lli cont(lli j,lli x,lli y)
// {
//     x%=mod;y%=mod;
//     // dbg(j,x,y,aa.best());
//     lli i;
//     repD(i,me-1,0)
//     {
//         if(aa.table[i]==0)
//             break;
//         if(aa.table[i]&(1LL<<j))
//         {
//             x+=y;
//             y=x;
//         }
//         else
//         {
//             x*=2;
//             y*=2;
//         }
//         x%=mod;y%=mod;
//     }

//     // if(y)   dbg(j,x,y);

//     return y;
// }

void merge(vii &b,vii &c)
{
    lli i,x,y;
    fo(i,me)
    {
        // if(chk(i))
        // {
        //     x=cont(i,b[i].X*c[i].X+b[i].Y*c[i].Y, );
        // }
        if(NN&(1LL<<i))
        {
            x=(b[i].X+b[i].Y)*(c[i].X+c[i].Y);
            x*=(1LL<<(N-1))%mod;
            x%=mod;
        }
        else
        {
            x=(1LL<<N)%mod;
            x*=b[i].Y*c[i].X+b[i].X*c[i].Y;
            x%=mod;
        }
        y=(1LL<<i)%mod;
        ans=(ans+x*y)%mod;
        b[i].X+=c[i].X;
        b[i].Y+=c[i].Y;
    }
}

void dfs2(lli u,lli p,vii &b)
{
    b.clear();
    lli i;
    fo(i,me)
    {
        if(a[u]&(1LL<<i))
            b.pb({0,1});
        else
            b.pb({1,0});
    }

    vii c;
    for(auto x:e[u])
    {
        if(x.X==p)
            continue;
        dfs2(x.X,u,c);
        merge(b,c);
    }

}

void add(lli root)
{
    aa=Gauss();
    // dbg(root,b[root],aa.table[me-1],aa.table[me-2]);
    // dbg(aa.size(),aa.best());
    dfs1(root,-1,0);
    NN=0;
    for(auto x:b[root])
    {
        aa.add(x.X^a[x.Y.X]^a[x.Y.Y]);
        // dbg(x.X^a[x.Y.X]^a[x.Y.Y]);
        NN|=x.X^a[x.Y.X]^a[x.Y.Y];
    }
    N=(lli)aa.size();
    // dbg(root,b[root],aa.table[me-1],aa.table[me-2]);
    // dbg(aa.size(),aa.best());
    vii b;
    dfs2(root,-1,b);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;

    repA(i,1,n)
        id[i]=i;

    fo(i,m)
    {
        cin>>u>>v>>w;
        if(root(u)==root(v))
            b[root(u)].pb({w,{u,v}});
        else
        {
            e[u].pb({v,w});
            e[v].pb({u,w});
            // id[root(u)]=root(v);
            merge1(root(u),root(v));
        }
    }

    repA(i,1,n)
    {
        if(id[i]!=i)
            continue;
        add(i);
    }

    cout<<ans<<endl;
}   aryanc403();
    return 0;
}