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
        vector<vi> A(n+1), B(n+1);
        for(int i=1; i<=n; i++){
            A[i].resize(n+1);
            B[i].resize(n+1);
            for(int j=1; j<=n; j++){
                cin>>A[i][j];
            }
        }
        vector<int> V={1, 2, 3}, V2={0, 0, 0};
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='D')V2[1]++;
            if(s[i]=='U')V2[1]--;
            if(s[i]=='R')V2[2]++;
            if(s[i]=='L')V2[2]--;
            if(s[i]=='C'){
                swap(V[0], V[1]);
                swap(V2[0], V2[1]);
            }
            if(s[i]=='I'){
                swap(V[0], V[2]);
                swap(V2[0], V2[2]);
            }
        }
        //cout<<V[0]<<" "<<V[1]<<" "<<V[2]<<" ";
        //cout<<V2[0]<<" "<<V2[1]<<" "<<V2[2]<<"\n";
        //cout<<"a";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int a=A[i][j]+V2[0], x=i+V2[1], y=j+V2[2];
                if(V[0]==2)a=i+V2[0];
                if(V[0]==3)a=j+V2[0];
                if(V[1]==1)x=A[i][j]+V2[1];
                if(V[1]==3)x=j+V2[1];
                if(V[2]==2)y=i+V2[2];
                if(V[2]==1)y=A[i][j]+V2[2];
                x=x%n;
                if(x<=0)x+=n;
                y=y%n;
                if(y<=0)y+=n;
                a=a%n;
                if(a<=0)a+=n;
                B[x][y]=a;
            }
        }
        for(int i=1; i<=n;i++){
            for(int j=1; j<=n; j++){
                cout<<B[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}