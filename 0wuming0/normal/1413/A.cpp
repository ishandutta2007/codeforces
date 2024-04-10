#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n/2;i++)
        {
            int p,q;
            cin>>p>>q;
            cout<<-q<<" "<<p<<" ";
        }
        cout<<endl;
    }
    return 0;
}