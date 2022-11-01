#include <iostream>

using namespace std;
int main() {
    
    int a[5],p=0;
    
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    p=a[0]+a[1]+a[2]+a[3]+a[4];
    if(p==0)
        cout<<-1;
    else if(p%5==0)
      cout<<p/5;  
    else if(p%5!=0)
      cout<<-1;   
    
    
    
    
    return 0;
}