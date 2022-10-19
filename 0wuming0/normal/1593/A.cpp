#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d %d %d\n",max(max(b,c)+1-a,0),max(max(a,c)+1-b,0),max(max(b,a)+1-c,0));
    }
    return 0;
}