#include <iostream>
#include <algorithm>
using namespace std;
#define N 200*1001
long long n,a[N],b[N],p,dif1[2],dif2[2];
int main() {
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
            dif1[p]=a[i];
            dif2[p]=b[i];
            p++;
            if(p>2)
            {
                cout<<"NO"<<endl;
                return 0;
            }
                
        }
    }   
    if(dif1[0]==dif2[1] && dif2[0]==dif1[1])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;   
        
    
    
    return 0;
}