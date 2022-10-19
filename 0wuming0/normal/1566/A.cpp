#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        scanf("%d%d",&n,&s);
        n=1+n/2;
        printf("%d\n",s/n);
    }
    return 0;
}