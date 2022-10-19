#include"bits/stdc++.h"
using namespace std;
int a[1000];
int pos[1000];
int cmp(int x,int y)
{
    return pos[x]<pos[y];
}
int main()
{
    srand(time(0));
    for(int i=0;i<1000;i++)pos[i]=rand();
    int n;cin>>n;
    while(n--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)a[i]=i;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            cout<<a[i]<<" \n"[i==n];
        }
    }
    return 0;
}