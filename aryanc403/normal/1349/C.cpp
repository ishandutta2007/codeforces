/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/
 
#include <bits/stdc++.h>
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

const int N = 1000L;

    lli i,j,n,m,t,p;
    string s;
    bitset<N> st[N];
    int chg[N][N];
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

const vii dir={{1,0},{-1,0},{0,1},{0,-1}};

lli get(lli itr,lli i,lli j)
{
    if(i<0||j<0||i>=n||j>=m)
        return -1;
    if(chg[i][j]==-1||chg[i][j]>p)
        return st[i][j];
    p-=chg[i][j]-1;
    p&=1;
    // dbg(st[i][j],p)
    return st[i][j]^p;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n>>m>>t;
    fo(i,n)
    {
        cin>>s;
        for(int j=0;j<m;++j)
            if(s[j]=='1')
                st[i][j]=1;
    }

    vii changes;
    memset(chg,-1,sizeof(chg));
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
    {
        for(auto x:dir)
        {
            if(get(0,i+x.X,j+x.Y)==st[i][j])
            {
                changes.pb({i,j});
                break;
            }
        }
    }

    dbg(changes);

    lli cur=1;
    while(!changes.empty())
    {
        vii nxt;
        dbg(cur)
        for(auto cell:changes)
        {
            chg[cell.X][cell.Y]=cur;
            dbg(cell,cur)
        }

        for(auto cell:changes)
        {
            const bool fl=!st[cell.X][cell.Y];
            for(auto x:dir)
            {
                i=cell.X+x.X;
                j=cell.Y+x.Y;
                if(i<0||j<0||i>=n||j>=m||chg[i][j]!=-1)
                    continue;
                dbg(st[i][j],fl);
                chg[i][j]=cur+1;
                if(st[i][j]==fl)
                    nxt.pb({i,j});
            }
        }
        changes.swap(nxt);
        cur++;
    }

    while(t--)
    {
        cin>>i>>j>>p;
        i--;j--;
        cout<<get(p,i,j)<<endl;
    }

}   aryanc403();
    return 0;
}