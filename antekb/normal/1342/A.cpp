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
    int t;
    cin>>t;
    while(t--){
        ll x, y, a, b;
        cin>>x>>y>>a>>b;
        if(2*a<b){
            b=2*a;
        }
        cout<<min(x, y)*b+abs(x-y)*a<<"\n";
    }
}