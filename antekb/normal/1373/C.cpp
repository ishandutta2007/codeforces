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
        string s;
        cin>>s;
        int n=sz(s);
        int k=0, ans=0, id=-1;
        ll res=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='+'){
                k++;
            }
            else{
                k--;
            }
            if(k<ans){
                res+=(i+1);
                ans=k;
                id=i;
            }
        }
        cout<<res+sz(s)<<"\n";
    }
}