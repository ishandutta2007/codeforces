#include"bits/stdc++.h"
using namespace std;
char s[100005];
int main()
{
    int t;
    cin>>t;
    scanf("%s",s);
    int a=0,b=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='n')a++;
        if(s[i]=='z')b++;
    }
    for(int i=0;i<a;i++)printf("1 ");
    for(int i=0;i<b;i++)printf("0 ");
    return 0;
}