#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=1e9+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<ll> V;
        for(int i=0; i<n; i++){
            string t;
            ll a=0;
            cin>>t;
            for(int j=0; j<m; j++){
                a<<=1;
                a+=(t[j]-'0');
            }
            V.push_back(a);
            //cout<<a<<"a";
        }
        sort(V.begin(), V.end());
        ll k=(((1ll)<<m)-n-1)/2;
        ll last=-1;
        for(ll i:V){
            if(i-last-1>k){
                break;
            }
            k-=(i-last-1);
            last=i;
        }
        ll l=(last+k+1);
        string t;
        //if(l==0)t.push_back('0');
        for(int i=0; i<m; i++){
            t.push_back((l&1)+'0');
            l/=2;
        }
        reverse(t.begin(), t.end());
        cout<<t<<"\n";
    }
}