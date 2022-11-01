#include <iostream>
using namespace std;
#define ll long long
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    ll n,t,c,a[200*1000],ans=0;
    cin>>n>>t>>c;
    for(int i=0;i<n;i++)
        cin>>a[i];  
    int temp=0,p=0,point;   
    for(point=0;point<n;point++)
    {
        if(a[point]<=t)
        {
            temp+=a[point];
            if(p<c)
                p++;
            if(p==c)
            {
                ans++;
                temp-=a[point-c];
            }                   
                
        }   
        else
        {
            p=0;
            temp=0;
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}