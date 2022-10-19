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
int tab[35][35];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int k=n+m-2;
        vi sum((n+m)/2), sum2((n+m)/2);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>tab[i][j];
                sum[min(i+j, k-i-j)]+=tab[i][j];
                sum2[min(i+j, k-i-j)]++;
            }
        }
        int res=0;
        for(int i=0; 2*i<k; i++){
            res+=min(sum[i], sum2[i]-sum[i]);
        }
        cout<<res<<"\n";
    }
}