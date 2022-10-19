#include"bits/stdc++.h"
using namespace std;
int num;
int n,k;
void pr(char c)
{
    putchar(c);
    num++;
    if(num==n)
    {
        cout<<endl;
        exit(0);
    }
}
void solve()
{
    pr('a');
    for(int i='b';i<='a'-1+k;i++)
    {
        pr(i);
        for(int j=i+1;j<='a'-1+k;j++)
        {
            pr(i);
            pr(j);
        }
        pr(i);
        pr('a');
    }
}
int main()
{
    cin>>n>>k;
    pr('a');
    while(1)
    {
        solve();
    }
    return 0;
}