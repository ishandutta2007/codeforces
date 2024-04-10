/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#undef endl
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

void solve(){
    const ii DONE = {INF,INF};
    const int N=8;
    map<string,ii> Results={
        {"Done",DONE},
        {"Right",{0,1}},
        {"Left",{0,-1}},
        {"Up",{-1,0}},
        {"Down",{1,0}},
        {"Down-Right",{1,1}},
        {"Down-Left",{1,-1}},
        {"Up-Left",{-1,-1}},
        {"Up-Right",{-1,1}},
    };
    dbg(Results);
    auto readKing=[&]()->ii{
        // lli x,y;cin>>x>>y;return {x,y};
        string s;
        cin>>s;
        return Results[s];
    };

    lli DX=0,DY=0;
    lli qx=0,qy=0;

    auto ext=[&](){
        return mp(DX,DY)==DONE;
    };

    auto QueenAttack=[&](lli x,lli y){
        return x==qx||y==qy||x+y==qx+qy||x-y==qx-qy;
    };

    auto placeQueen=[&](lli x,lli y){
        assert(0<=x&&x<N&&0<=y&&y<N);
        assert(QueenAttack(x,y));
        qx=x;
        qy=y;
        cout<<x+1<<" "<<y+1<<endl;
        const auto dr=readKing();
        if(dr==DONE){
            tie(DX,DY)=DONE;
        } else {
            DX+=dr.X;
            DY+=dr.Y;
        }
    };
    placeQueen(0,0);
    auto playRow=[&](const lli row){
        lli r;
        auto updateKingRow=[&](){
            r=row+DX;
        };
        updateKingRow();
        if(r<0||r>=N)
            return;
        if(qy!=0)
            placeQueen(qx,0);
        for(int i=0;i<2*N-3;++i){
            if(ext())
                return;
            updateKingRow();
            if(r==qx)
                return;
            if(abs(r-qx)==1){
                if(qy==N-1)
                    return;
                placeQueen(qx,qy+1);
            } else if(r<qx){
                if(qx==0)
                    return;
                placeQueen(qx-1,qy);
            } else {
                if(qx==N-1)
                    return;
                placeQueen(qx+1,qy);
            }
        }
    };

    for(int i=0;i<N;++i){
        if(ext())
            return;
        playRow(i);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
lli T;
cin>>T;while(T--)
{
    solve();
}   aryanc403();
    return 0;
}