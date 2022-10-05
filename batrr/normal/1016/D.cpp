#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=2e5+123,inf=1e18,mod=1e9+7;
int n,m,a[150],b[150],c[150][150],x,y;
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    IOS                            
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x^=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        y^=b[i];
    }
    if(x!=y)
        cout<<"NO",exit(0);
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        c[i][1]=a[i];
    }
    c[n][1]=x^b[1]^a[n];
    for(int i=2;i<=m;i++)
        c[n][i]=b[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}