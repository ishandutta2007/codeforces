#include <iostream>
using namespace std;

int main(){
 long long int n,m,d=0;
 cin>>n>>m;
 if(n==m)
 {
    cout<<"infinity";
    return 0;
 }
 if(n<m)
 {
    cout<<0;
    return 0;
 }
 long long int u=n-m;
 for(int i=1;i*i<=u;i++)
 {
        if(u%i==0)
        {
            if(i*i==u && i>m)
                d++;
            else
            {
                if(i>m)
                    d++;
                if(u/i>m)
                    d++;    
            }
        }
 }
 cout<<d;
}