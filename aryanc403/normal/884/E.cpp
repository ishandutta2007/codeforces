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
#define sz(x) (int)(x).size()
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

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
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
const lli N = 1LL<<12;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    // string s[N];
    vi a;
    bitset<4*N> vis[N];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

bool isOn(const string &s,lli y)
{
    // return true;
    #ifdef ARYANC403
    return s[y]-'0';
    #endif

    // return true;
    char c=s[y/4];
    lli v=0;
    if('0'<=c&&c<='9')
        v=c-'0';
    else
        v=c-'A'+10;
    // lli k=y;
    y%=4;
    y=3-y;
    // dbg(v&(1<<y) );
    return v&(1<<y);
}

struct UF {
	vi e;
	UF(int n) : e(n) {
        for(lli i=0;i<n;++i)
            e[i]=i;
        // dbg(e);
    }

	bool same_set(int a, int b) { return find(a) == find(b); }
	int find(int x) { return (e[x] == x) ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		e[b] = a;
		return true;
	}

    void reinit(){
        const lli n=sz(e);
        vi m(n);
        for(lli i=n/2;i<n;++i)
            m[find(i)]=i-n/2;
        dbg("pvr",e,m);
        for(lli i=n/2;i<n;++i)
        {
            e[i-n/2]=m[e[i]];
            e[i]=i;
        }
        dbg("aft",e);
    }

};

// void bfs(lli x,lli y)
// {
//     const vii dr={{-1,0},{1,0},{0,1},{0,-1}};
//     queue<lli> st;
//     st.push({x*m+y});
//     dbg(x,y);
//     vis[x][y]=0;
//     while(!st.empty())
//     {
//         // dbg(st);
//         // vi gt;
//         auto u=st.front();st.pop();
//         // for(auto u:st)
//         {
//             lli x=u/m,y=u%m;
//             for(auto z:dr)
//             {
//                 if(x+z.X<0||x+z.X>=n||y+z.Y<0||y+z.Y>=m||!vis[x+z.X][y+z.Y])
//                     continue;
//                 // dbg(x+z.X,y+z.Y)
//                 vis[x+z.X][y+z.Y]=0;
//                 st.push((x+z.X)*m+y+z.Y);
//             }
//         }

//         // if(st.empty())
//             // gt.swap(st);
//     }
// }

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    // n=N;m=4*n;
    dbg(n,N,m,4*n);
    lli ans=0;
    fo(i,n)
    {
        string s;
        cin>>s;
        fo(j,m)
        {
            vis[i][j]=isOn(s,j);
            ans+=vis[i][j];
        }
    }

    UF b(2*m);
    fo(i,n){
        fo(j,m-1)
        {
            if(vis[i][j]&&vis[i][j+1])
            {
                dbg(i,j,j+1,vis[i][j],vis[i][j+1])
                ans-=b.join(j+m,j+m+1);
            }
        }

        if(i==0)
        {
            b.reinit();
            continue;
        }

        fo(j,m)
        {
            if(vis[i][j]&&vis[i-1][j])
            {
                dbg(i,i-1,j,vis[i][j],vis[i][j+1])
                ans-=b.join(j,j+m);
            }
        }

        b.reinit();
    }

    cout<<ans<<endl;

}   aryanc403();
    return 0;
}