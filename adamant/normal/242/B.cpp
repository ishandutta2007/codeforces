#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    
    cin>>n;
    
    int*l=new int[n];
    int*r=new int[n];
    int ans=-1;
    bool ok=false;
    int max;
    int min;
    for(int i=0;i<n;i++)
    {
    cin>>l[i]>>r[i];
    if(i==0)
    {
    min=l[i];
    max=r[i];
    ans=1;
    ok=true;
    }
    if(l[i]<=min || r[i]>=max)
    {
                 if(l[i]<=min && r[i]>=max)
                 {
                 min=l[i];
                 max=r[i];
                 ans=i+1;
                 ok=true;
                 }
                 else if(l[i]<min)
                 {
                 min=l[i];
                 ans=-1;
                 ok=false; 
                 }
                 else if(r[i]>max)
                 {
                 max=r[i];
                 ans=-1;
                 ok=false;    
                 }
                 
    }
    }
    if(ok)
    cout<<ans<<endl;
    else
    cout<<-1<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}