#include"bits/stdc++.h"
using namespace std;
char s[200005];
int ans[2000];
int save[300],nn;
int main()
{
    scanf("%s",s);
    for(int i=0;s[i];i++)ans[s[i]]++;
    for(int i='a';i<='z';i++)
    {
        if(ans[i]%2)save[nn++]=i;
    }
    for(int i=0,j=nn-1;i<j;i++,j--)
    {
        ans[save[i]]++;
        ans[save[j]]--;
    }
    for(int i='a';i<='z';i++)
    {
        for(int num=0;num<ans[i]/2;num++)
            putchar(i);
    }
    if(nn%2)putchar(save[nn/2]);
    for(int i='z';i>='a';i--)
    {
        for(int num=0;num<ans[i]/2;num++)
            putchar(i);
    }
    putchar(10);
    return 0;
}