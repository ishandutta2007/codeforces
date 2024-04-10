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

int x[N],y[N];
map<int,vector<pir > > mp;

int main(){
    fastio;
    srng;
    int n;
    cin>>n;
    FOR(i,n*4+1){
        cin>>x[i]>>y[i];
        x[i]*=2;
        y[i]*=2;
        //mp[max(abs(x[i]),abs(y[i]))].ad({x,y});
    }
    FORT(i,-100,100){
        FORT(j,-100,100){
            FOR(t,n*4+1){
                mp[max(abs(x[t]-i),abs(y[t]-j))].ad({x[t],y[t]});
            }
            if (mp.size()==2)
            trav(tv,mp){

                if (tv.sc.size()==1){
                    cout<<tv.sc[0].fr/2<<" "<<tv.sc[0].sc/2<<endl;
                    return 0;
                }
            }
            mp.clear();
        }
    }

    return 0;
}