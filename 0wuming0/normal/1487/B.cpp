#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        k--;
        if(n%2==0)
        {
            cout<<k%n+1<<endl;
        }
        else
        {
            k+=k/(n/2);
            cout<<k%n+1<<endl;
        }
    }
    return 0;
}