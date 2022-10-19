#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    char s[3000]={0};
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=0;i<b-c;i++)s[i]='a';
        int k=b-c,ch='a';
        while(c--){s[k]=ch;ch++;k++;}
        for(int i=0;i<a;i++)
        {
            putchar(s[i%b]);
        }putchar(10);
    }
    return 0;
}