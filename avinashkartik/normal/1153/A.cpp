#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 3e5+3;

ll a[N][2],vis[N],ans;
ll n,sum,t,k,ind;
string s;
stack <ll> st;
ll m;

int main(){
    cin>>n>>t;
    for(int i=0; i<n; i++){
        cin>>a[i][0]>>a[i][1];
        while(a[i][0] < t) a[i][0] += a[i][1];
    }
    m =INF, ind = -1;
    for(int i=0; i<n; i++){
        if(a[i][0] < m){
            m = a[i][0];
            ind = i+1 ;
        }
    }
    cout<<ind<<endl;
}