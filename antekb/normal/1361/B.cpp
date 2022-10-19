#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=1e9+5, mod=1e9+7;
int pot(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    ll c=pot(a, b/2);
    c=(c*c)%mod;
    return (c*1ll*pot(a, b&1))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        int n, p;
        vi V;
        cin>>n>>p;

        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            V.push_back(x);
        }
        if(p==1){ cout<<n%2<<"\n"; continue;}
        sort(V.begin(), V.end());
        while(true){
            while(V.size()>=2 && V[V.size()-1]==V[V.size()-2]){
                V.resize(V.size()-2);
            }
            if(V.size()==0){
                cout<<"0\n";
                break;
            }
            if(V.size()==1){
                cout<<pot(p, V[0])<<"\n";
                break;
            }
            int id=-1;
            ll w=1;
            for(int i=V.size()-2; i>=0; --i){
                int x=V[i+1]-V[i];
                while(x--  && w<=INF){
                    w=w*p;
                }
                if(w>INF)break;
                else w--;
                if(w==0){
                    id=i;
                    break;
                }
            }
            if(id!=-1){
                V.resize(id);
                continue;
            }
            else{
                ll res=0;
                for(int i=V.size()-1; i>=0; i--){
                    if(i==V.size()-1) res-=pot(p, V[i]);
                    else res+=pot(p, V[i]);
                }
                res=((-res)%mod+mod)%mod;
                cout<<res<<"\n";
                break;
            }
        }
    }
}