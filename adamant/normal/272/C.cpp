#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define ll long long

int main()
{   
    int n;
    cin>>n;
    ll*a=new ll[n];

    for(int i=0;i<n;i++)
    cin>>a[i];
    
    int m;
    cin>>m;
    ll*w=new ll[m];
    ll*h=new ll[m];
    ll curh=0;
    for(int i=0;i<m;i++)
    {
    cin>>w[i]>>h[i];
    ll c;
    c=max( curh , a[w[i]-1] );
    cout<<c<<endl;
    curh=c+h[i];
    }
    
    
    
    return 0;
}