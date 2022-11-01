#include <iostream>
using namespace std;
#define N (1001)
int n,m,a,b,x[N][N],x2[N],ans,ans2;
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        x[a][b]++;
        x2[b]++;
    }
        
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(x[a][b]>0)
        {
            x[a][b]--;
            ans2++;
        }
        if(x2[b]>0)
        {
            x2[b]--;
            ans++;
        }
    }
    cout<<ans<<" "<<ans2<<endl; 
            
    
    return 0;
}