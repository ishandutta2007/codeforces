#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const ll maxn=4e5+123,inf=1e18,mod=1e9+7;
int sy,a,b,n,q,l[maxn],r[maxn],Y[maxn];
double ans[maxn],sum;  
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    scanf("%d%d%d",&sy,&a,&b);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);     
    scanf("%d",&q);
    vector< pair<double ,int > > v;
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        Y[i]=y;                 
        v.pb({(1.0*y*a-1.0*x*sy)/(y-sy),i+i});
        v.pb({(1.0*y*b-1.0*x*sy)/(y-sy),i+i+1});
    }
    sort(v.begin(),v.end());
    l[n+1]=1e9+123;
    r[n+1]=1e9+123;
    for(int i=1,j=0;i<=n+1;i++){
        while(j<v.size()){
            double x=v[j].f;
            if( x>r[i] )
                break;
            ans[v[j].s]=max(0.0,x-l[i])+sum;
            j++;
        }
        sum+=r[i]-l[i];
    }
    for(int i=1;i<=q;i++){
        double res=ans[i+i+1]-ans[i+i];
        cout<<fixed<<setprecision(10)<<res/Y[i]*(Y[i]-sy)<<endl;
    }
}