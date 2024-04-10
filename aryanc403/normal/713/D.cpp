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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;
#define rep(i, from, to) for (int i = from; i < (to); ++i)
typedef long long ll;
typedef pair<int, int> pii;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
        b++;
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

const lli N=2048;
    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vector<vector<bool>> a;
    vector<vi> b(1);
    vector<RMQ<lli>> bf(N,RMQ<lli>(b[0]));
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

// lli queryy(lli a[N],lli id,lli l,lli r,lli L,lli R)
// {
//     if(r<L||R<l)
//         return 0;
//     if(L<=l&&r<=R)
//         return a[id];
//     lli m=(l+r)/2;
//     return max(queryy(a,2*id,l,m,L,R),queryy(a,2*id+1,m+1,r,L,R));
// }

lli queryx(lli id,lli l,lli r,lli L,lli R,lli ly,lli ry)
{
    if(r<L||R<l)
        return 0;
    if(L<=l&&r<=R)
        return bf[id].query(ly,ry);
    lli m=(l+r)/2;
    return max(queryx(2*id,l,m,L,R,ly,ry),queryx(2*id+1,m+1,r,L,R,ly,ry));
}

lli query(lli lx,lli rx,lli ly,lli ry)
{
    dbg(lx,rx,ly,ry,queryx(1,0,n-1,lx,rx,ly,ry));
    return queryx(1,0,n-1,lx,rx,ly,ry);
}

// void buildy(lli a[N],const vi &b,lli id,lli l,lli r)
// {
//     if(l==r)
//     {
//         a[id]=b[l];
//         return;
//     }
//     lli m=(l+r)/2;
//     buildy(a,b,2*id,l,m);
//     buildy(a,b,2*id+1,m+1,r);
//     a[id]=max(a[2*id],a[2*id+1]);
// }

void buildx(lli id,lli l,lli r)
{
    if(l==r)
    {
        // buildy(bf[id],b[l],1,0,m-1);
        bf[id]=RMQ<lli>(b[l]);
        return;
    }
    lli mid=(l+r)/2;
    buildx(2*id,l,mid);
    buildx(2*id+1,mid+1,r);
    vi b;
    for(lli i=0;i<m;i++)
        b.pb(max(bf[2*id].query(i,i),bf[2*id+1].query(i,i)));
    bf[id]=RMQ<lli>(b);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    a.resize(n,vector<bool>(m));
    b.clear();
    b.resize(n,vi(m,0));

    fo(i,n)
    {
        fo(j,m)
        {
            cin>>in;
            a[i][j]=(in==1);
        }
        // cout<<s<<endl;
    }
    // dbg(a);

    repD(i,n-1,0)
    repD(j,m-1,0)
    {
        if(a[i][j])
            b[i][j]=1;
        if(i==n-1||j==m-1)
            continue;
        if(!a[i][j]||!a[i+1][j])
            continue;
        if(!a[i][j+1])
            continue;
        if(!a[i+1][j]||!a[i+1][j+1])
            continue;
        if(!a[i][j+1]||!a[i+1][j+1])
            continue;
        // dbg(i,j,b[i+1][j+1],b[i+1][j],b[i][j+1]);
        b[i][j]=1+min({b[i+1][j+1],b[i+1][j],b[i][j+1]});
    }
    dbg(a);
    dbg(b);
    buildx(1,0,n-1);
    lli q;
    cin>>q;
    while(q--)
    {
        lli x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;y1--;x2--;y2--;
        dbg(x1,y1,x2,y2);
        lli l=0,r=min(x2-x1+1,y2-y1+1)+1;
        while(r-l>1)
        {
            const lli len=(l+r)/2;
            if(query(x1,x2-len+1,y1,y2-len+1)>=len)
                l=len;
            else
                r=len;
        }
        cout<<l<<endl;
    }

}   aryanc403();
    return 0;
}