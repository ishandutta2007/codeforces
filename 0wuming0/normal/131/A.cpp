#include"bits/stdc++.h"
using namespace std;
char s[105];
int main()
{
    scanf("%s",s);
    for(int i=1;s[i];i++)
    {
        if('a'<=s[i]&&s[i]<='z')
        {
            printf("%s\n",s);
            return 0;
        }
    }
    for(int i=1;s[i];i++)s[i]+='a'-'A';
    if('a'<=s[0]&&s[0]<='z')s[0]=s[0]+'A'-'a';
    else s[0]=s[0]+'a'-'A';
    printf("%s\n",s);
    return 0;
}