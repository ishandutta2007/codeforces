#include"bits/stdc++.h"
using namespace std;
int ch(char c)
{
    if(c=='a')return 1;
    if(c=='o')return 1;
    if(c=='e')return 1;
    if(c=='i')return 1;
    if(c=='u')return 1;
    if(c=='n')return 2;
    return 0;
}
int main()
{
    char s[105];scanf("%s",s);
    int n=strlen(s);
    if(!ch(s[n-1]))cout<<"NO";
    else
    {
        for(int i=0;i<n-1;i++)
        {
            if(ch(s[i])==0&&ch(s[i+1])!=1)
            {
                cout<<"NO";return 0;
            }
        }
        cout<<"YES";
    }
    return 0;
}