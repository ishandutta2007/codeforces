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
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
string chr="";
for(int i=0;i<26;++i)
    chr+=(char)(i+'a');
cin>>T;while(T--)
{
    const lli N=4;
    cin>>n>>m>>k;
    dbg(n,m,k);
    vector<string> a(n,string(m,'.'));
    lli jj=0;

    auto nc=[&](lli k){
        if(k==2){
            jj=(jj+1)%2;
        } else {
            jj=(jj+1)%N;
        }
        // dbg(N,k,jj);
        return chr[N*k+jj];
    };

    auto getSingle=[&](){
        auto &s=a[n-1];
        for(lli i=0;i<m;i+=2){
            s[i]=s[i+1]=nc(2);
        }
    };

    if(n&1){
        getSingle();
        k-=m/2;
        n--;
    }
    if(k<0){
        cout<<"NO"<<endl;
        continue;
    }

    if(k%2||k>n*(m/2)){
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
    lli c=0;
    for(lli i=0;i<n;i+=2){
        jj=0;
        for(lli j=0;j<m;++j){
            if(j+1==m||k==0){
                a[i][j]=a[i+1][j]=nc(c);
                continue;
            }
            a[i][j]=a[i][j+1]=nc(c);
            a[i+1][j]=a[i+1][j+1]=nc(c);
            j++;
            k-=2;
        }
        c^=1;
    }

    for(auto &s:a)
        cout<<s<<endl;

}   aryanc403();
    return 0;
}