////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long

int main()
{
    ll a,b;
    cin>>a>>b;
    for(int i=0;i<a+1;i++)
        cout<<b+i+1<<" ";
    for(int i=b-1;i>=0;i--)
        cout<<i+1<<" ";
    
    return 0;
}