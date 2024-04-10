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
const int N=1e7+5,M=5e5+5, INF=2e9+5, mod=1e9+7;
int sito[N+1];
int ans[M], ans2[M];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=2; i<N; i++){
        if(!sito[i]){
            for(int j=i; j<=N/i; j++){
                sito[i*j]=i;
            }
        }
    }
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        if(sito[k]==0){
            ans[i]=-1;
            ans2[i]=-1;
        }
        else{
            int t=sito[k], u=1;
            while(!(k%t)){
                k/=t;
                u*=t;
            }
            if(k==1){
                ans[i]=-1;
                ans2[i]=-1;
            }
            else{
                ans[i]=k;
                ans2[i]=u;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<n; i++){
        cout<<ans2[i]<<" ";
    }
}