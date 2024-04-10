#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, l;
        cin>>n>>l;

        vi V(n+1);
        for(int i=1; i<=n; i++){
            cin>>V[i];
        }
        V.pb(l);
        ld v1=1, v2=1;
        ld t1=0, t2=0;
        while(v1+v2<n+2){
            ld T1=(V[v1]-V[v1-1])/v1, T2=(V[n-v2+2]-V[n-v2+1])/v2;
            if(t1+T1<T2+t2){
                t1+=T1;
                v1++;
            }
            else{
                t2+=T2;
                v2++;
            }
            //cout<<t1<<" "<<t2<<"\n";
        }

        ld dist=V[v1]-V[v1-1];
        //cout<<dist<<"\n";
        if(t1<t2){
            dist-=v1*(t2-t1);
            t1=t2;
        }
        else dist-=v2*(t1-t2);
        //cout<<dist<<"\n";
        t1+=(dist)/(v1+v2);

        cout<<fixed<<setprecision(10)<<t1<<"\n";
    }
}