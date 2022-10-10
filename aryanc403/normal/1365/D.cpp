/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
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

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
const vii dir={{0,-1},{0,1},{1,0},{-1,0}};

cin>>T;while(T--)
{

    vector<string> a;
    cin>>n>>m;
    a.clear();a.reserve(n);
    fo(i,n)
    {
        cin>>s;
        a.pb(s);
    }

    auto chk=[&](const lli x,const lli y){
        return 0<=x&&x<n&&0<=y&&y<m;
    };

    bool fl=true;
    fo(i,n)
    fo(j,m)
    {
        if(a[i][j]!='B')
            continue;
        for(auto x:dir)
        {
            x.X+=i;x.Y+=j;
            if(!chk(x.X,x.Y))
                continue;
            if(a[x.X][x.Y]=='G')
            {
                fl=false;
                break;
            }
            if(a[x.X][x.Y]!='.')
                continue;
            a[x.X][x.Y]='#';
        }
    }

    UF uf(n*m);
    fo(i,n)
    fo(j,m)
    {
        if(a[i][j]=='#')
            continue;
        for(auto x:dir)
        {
            x.X+=i;x.Y+=j;
            if(!chk(x.X,x.Y)||a[x.X][x.Y]=='#')
                continue;
            uf.join(i*m+j,x.X*m+x.Y);
        }
    }

    fo(i,n)
    fo(j,m)
    {
        if(a[i][j]=='G'&&uf.find(i*m+j)!=uf.find(n*m-1))
            fl=false;
    }

    cout<<(fl?"Yes":"No")<<endl;

}   aryanc403();
    return 0;
}