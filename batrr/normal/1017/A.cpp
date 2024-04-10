#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;

int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif
    int n;
    vector< pair< int,int> >v;                           
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.pb({-(a+b+c+d),i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        if(v[i].s==1)
            cout<<i+1;
}