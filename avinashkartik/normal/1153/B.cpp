#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;
const int N = 103;

ll a[N][N],vis[N],ans;
ll n,sum,t,k,ind;
string s;
stack <ll> st;
ll m,h[N];

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>vis[i];
    }
    for(int i = 0; i<n; i++){
        cin>>h[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] != 0 && vis[j] >= h[i])
                a[i][j] = h[i];
            else if(a[i][j] != 0)
                a[i][j] = vis[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}