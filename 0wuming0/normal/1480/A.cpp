#include"bits/stdc++.h"
using namespace std;
char s[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s);
        for(int i=0;s[i];i++)
        {
            if(i%2==0)
            {
                if(s[i]=='a')s[i]='b';
                else s[i]='a';
            }
            else
            {
                if(s[i]=='z')s[i]='y';
                else s[i]='z';
            }
        }
        printf("%s\n",s);
    }
    return 0;
}