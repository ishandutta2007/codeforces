#include"bits/stdc++.h"
using namespace std;

int main()
{
    long long k;
    cin>>k;
    char s[100]="codeforces";
    int a[100];
    for(int i=0;i<10;i++)a[i]=1;
    long long now=1;
    int t=0;
    while(now<k)
    {
        now=now/a[t];
        a[t]++;
        now=now*a[t];
        t++;
        t%=10;
    }
    for(int i=0;i<10;i++)for(int j=0;j<a[i];j++)putchar(s[i]);
    cout<<endl;
    return 0;
}