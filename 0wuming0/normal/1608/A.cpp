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
        for(int i=0;i<n;i++)printf("%d%c",i+3," \n"[i==n-1]);
    }
    return 0;
}