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

    string t;
    cin>>t;
    vector<char> V;
    vector<vector<char> > V2(t.size());
    int n=0;
    vector<int> ans(t.size());
    vi zle;
    stack<char> nxt;
    nxt.push('a'-1);
    for(int i=t.size()-1; i>=0; i--){
        V.pb(t[i]);
        n++;
        if(n>1 && V[n-1]==V[n-2] && (n==2 || V[n-2]>nxt.top()) && (!zle.size() || zle[zle.size()-1]!=n-1)){
            if(n>2 && V[n-2]!=V[n-3])nxt.pop();
            V.pop_back();
            V.pop_back();
            n-=2;

            zle.pb(n);
        }
        if(n>1 &&V[n-1]!=V[n-2])nxt.push(V[n-2]);
        ans[i]=n;
        string s;
        if(n>10){
            for(int j=n-1; j>=n-5; j--)V2[i].pb(V[j]);
            V2[i].resize(8, '.');
            for(int j=1; j>=0; j--)V2[i].pb(V[j]);
        }
        else{
            for(int j=n-1; j>=0; j--){
                V2[i].pb(V[j]);
            }

        }
    }
    for(int i=0; i<t.size(); i++){
        cout<<ans[i]<<" ";
        for(char c:V2[i])cout<<c;
        cout<<"\n";
    }
}