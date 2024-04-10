#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N=1e5+5, INF=1e9+5;
int tab[40005];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b, q;
        cin>>a>>b>>q;
        for(int i=1; i<=a*b; i++){
            if((i%a)%b!=(i%b)%a){
                tab[i]=tab[i-1]+1;
            }
            else tab[i]=tab[i-1];
        }
        long long k=tab[a*b], m=a*b;
        while(q--){
            ll l, r;
            cin>>l>>r;
            l--;
            cout<<(r/m)*k+tab[r%m]-((l/m)*k+tab[l%m])<<" ";
        }
        cout<<"\n";
    }
}