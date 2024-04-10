#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        cout<<(24-n)*60-m<<endl;
    }
    return 0;
}