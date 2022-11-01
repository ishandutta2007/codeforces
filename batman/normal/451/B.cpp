#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,a[100*1001],b[100*1001],p=0,index[2]={1,1};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if(p>0)
            {
                cout<<"no";
                return 0;
            }
            index[0]=i+1;
            
            for(;a[i]>a[i+1] && i<n-1;i++);
            index[1]=i+1;
            p++;
        }      
    }   
    cout<<"yes"<<endl;
    cout<<index[0]<<" "<<index[1];
        
    return 0;
}