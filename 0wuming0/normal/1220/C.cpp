#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[500005];
int main()
{
    scanf("%s",s);
    char c='z';
    for(int i=0;s[i];i++)
    {
        if(c<s[i])printf("Ann\n");
        else printf("Mike\n");
        c=min(c,s[i]);
    }
    return 0;
}