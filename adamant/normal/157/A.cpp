#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    
    cin>>n;
    
    int**tab=new int*[n];
    
    int*sum1=new int[n];
    
    int*sum2=new int[n];
    
    for(int i=0;i<n;i++)    
    {
            tab[i]=new int[n];
            for(int j=0;j<n;j++)
            cin>>tab[i][j];
    }
    
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
            int sum1=0;
            int sum2=0;
            
            for(int k=0;k<n;k++)
            {
                    sum1+=tab[k][j];
                    sum2+=tab[i][k];                    
            }
            
            if(sum1>sum2)
            ans++;
    }
    
    }
    
    cout<<ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}