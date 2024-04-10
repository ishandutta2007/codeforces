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
        cout<<n<<endl;
        for(int i=0;i<n;i++)
            printf("%d%c",i+1," \n"[i==n-1]);
    }
    return 0;
}