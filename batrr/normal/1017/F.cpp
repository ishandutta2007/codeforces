#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

#define ui unsigned int 

using namespace std;                    

const int maxn=2e5+123,N=2e4;

bitset< N+123 > was;
ui n,a,b,c,d,ans,x;
vector< ui > p;
int get(ui p,ui n){
    if(p>n || p==1)
        return 0;
    return n/p+get(p,n/p);
}
bool prime(int i){
     for(int j=2;j*j<=i;j++) 
          if(i%j==0)
               return 0;
               return 1;
}
int main(){
    #ifdef LOCAL
        freopen ("test.in", "r", stdin);
    #endif                                     
    
    cin>>n>>a>>b>>c>>d;
    for(ui i=2;i<=N;i++)
        if(!was[i]){
            p.pb(i);
            for(int j=i+i;j<N;j+=i)
                was[j]=1;
        }
    for(int l=1;l<=3e8;l+=N){
        
        int r=l+N-1;
        
        was.reset();
        
        for(auto v:p)
            for(int i=(l+v-1)/v*v;i<=r;i+=v)
               if(i!=v)
                    was[i-l]=1;
        
        //cout<<l<<" "<<r<<endl;

          for(int j=0;j<N;j++)
            if(!was[j]){
                ui i=j+l;
                x=get(i,n);
                ans+=x*(a*i*i*i+b*i*i+c*i+d);
          }
                    
    }
    cout<<ans;
}