#include <iostream>
using namespace std;
int n,nn[2],q;


int main() {
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q;
        if(q==5)
            nn[1]++;
        else
            nn[0]++;    
    }
    if(nn[0]==0)
    {
        cout<<-1<<endl;
        return 0;
    }   
    if(nn[1]<9)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<nn[1]-nn[1]%9;i++)
        cout<<5;
    for(int i=0;i<nn[0];i++)
        cout<<0;    
    cout<<endl;
    return 0;
}