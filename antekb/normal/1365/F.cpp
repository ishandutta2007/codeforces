#include<bits/stdc++.h>
#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=(1<<20)+5, INF=2e9+5, mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n), b(n);
        for(int &i:a){
            cin>>i;
        }
        for(int &i:b){
            cin>>i;
        }
        vector<pii> V, V2;
        for(int i=0; 2*i<n-1; i++){
            V.pb(mp(min(a[i], a[n-1-i]), max(a[i], a[n-1-i])));
            V2.pb(mp(min(b[i], b[n-1-i]), max(b[i], b[n-1-i])));
        }
        sort(all(V));
        sort(all(V2));
        if(V==V2 && (n%2==0 || a[n/2]==b[n/2]))cout<<"yes\n";
        else cout<<"No\n";
    }
}