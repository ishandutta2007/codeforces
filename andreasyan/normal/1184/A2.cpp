#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define ad push_back
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define all(v) v.begin(),v.end()
#define make_unique(v) v.erase(unique(all(v),v.end()))
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define dbg(x);
#define dbgv(v);
#define srng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define y1 EsiHancagorcRepa



const int N=1e6+6;

int pat[N],qan[N];

int main(){
    fastio;
    srng;
    int n;
    cin>>n;
    string s;
    cin>>s;
    FORT(i,1,n){
        if (n%i)continue;
        FOR(j,n){
            qan[j%i]+=s[j]-'0';
        }
        pat[i]=1;
        //cout<<qan[0]<<" "<<qan[1]<<" ";
        FOR(j,i){
            if (qan[j]%2){
                pat[i]=0;
            }
            qan[j]=0;
        }
        //cout<<i<<" "<<pat[i]<<endl;
    }
    int ans=0;
    FOR(i,n){
        int tv=__gcd(n,i);
        //cout<<tv<<endl;
        ans+=pat[tv];
    }
    cout<<ans<<endl;
    return 0;
}