#include <iostream>
using namespace std;
int n,m,r,ans;
char a[11][11];
int main() {
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int p=0;
        for(int j=0;j<m;j++)
            if(a[i][j]=='S')
            {
                p++;
                break;
            }
            
        if(p==0)
        {
            ans+=m;
            r++;
        }       
    }   
    for(int i=0;i<m;i++)
    {
        int p=0;
        for(int j=0;j<n;j++)
            if(a[j][i]=='S')
            {
                p++;
                break;
            }
            
        if(p==0)
            ans+=n-r;
    }   
    cout<<ans<<endl;
    
    return 0;
}