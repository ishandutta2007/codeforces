#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vi> V(n);
        for(int i=0; i<n; i++){
            V[i].resize(m);
            string s;
            cin>>s;
            for(int j=0; j<m; j++){
                V[i][j]=s[j]-'0';
            }
        }
        vii Q;
        for(int s=m+n-2; s>2; s--){
            for(int d=max(-s, s-2*m)+2; d<s && d<2*n-s; d+=2){
                int i=(s+d)/2, j=(s-d)/2;//cout<<s<<" "<<d<<" "<<i<<" "<<j<<"\n\n";
                if(V[i][j]){
                    Q.pb(mp(i, j));
                    V[i][j]^=1;
                    if((i==1&&V[i-1][j])||(i!=1)){
                        Q.pb(mp(i-1, j));
                        V[i-1][j]^=1;
                    }
                    if((j==1&&V[i][j-1])||(j!=1)){
                        Q.pb(mp(i, j-1));
                        V[i][j-1]^=1;
                    }
                    if(sz(Q)%3){
                        Q.pb(mp(i-1, j-1));
                        V[i-1][j-1]^=1;
                    }
                }
            }
            if(s<=n&&V[s-1][0]==1){
                Q.pb(mp(s-1, 0));
                Q.pb(mp(s-2, 0));
                Q.pb(mp(s-2, 1));
                V[s-1][0]^=1;
                V[s-2][0]^=1;
                V[s-2][1]^=1;
            }
            if(s<=m&&V[0][s-1]==1){
                Q.pb(mp(0,s-1));
                Q.pb(mp(0,s-2));
                Q.pb(mp(1,s-2));
                V[0][s-1]^=1;
                V[0][s-2]^=1;
                V[1][s-2]^=1;
            }
        }
        //cout<<Q.size()<<"\n";
            vii V2={mp(0, 0), mp(0, 1), mp(1, 1), mp(1, 0)};
            int ile=0;
            for(auto k:V2){
                if(V[k.st][k.nd])ile++;
            }
            //cout<<Q.size()<<" "<<ile<<"\n";
            if(ile==4){
                ile=1;
                int c=0;
                for(auto k:V2){
                    if(c++<3){
                        V[k.st][k.nd]^=1;
                        Q.pb(k);
                    }
                }
            }
            if(ile==1){
                int c=0;
                for(auto k:V2){
                    if(V[k.st][k.nd]){
                        //cout<<"a";
                        Q.pb(k);
                        V[k.st][k.nd]^=1;
                    }
                    else if(c++<2){
                        //cout<<"b";
                        Q.pb(k);
                        V[k.st][k.nd]^=1;
                    }
                }
                //cout<<Q.size();
                ile++;
            }
            if(ile==2){
                int c=0;
                for(auto k:V2){
                    if(!V[k.st][k.nd]){
                        //cout<<"a";
                        Q.pb(k);
                        V[k.st][k.nd]^=1;
                    }
                    else if((c++<1)){
                        //cout<<"b";
                        Q.pb(k);
                        V[k.st][k.nd]^=1;
                    }
                }
                //cout<<Q.size();
                ile++;
            }
            if(ile==3){
                for(auto k:V2){
                    if(V[k.st][k.nd])
                        Q.pb(k);
                }
            }
            cout<<sz(Q)/3<<"\n";
            for(int i=0; i<Q.size(); i++){
                cout<<Q[i].st+1<<" "<<Q[i].nd+1<<" \n"[(i%3)==2];
            }
    }
}