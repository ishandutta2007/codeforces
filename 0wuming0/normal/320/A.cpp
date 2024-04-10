#include"bits/stdc++.h"
using namespace std;
int main()
{
    char s[40];
    scanf("%s",s);
    int flag=0,num=10000;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='1')
        {
            num=0;
        }
        else if(s[i]=='4')
        {
            num++;
            if(num>2)flag=1;
        }
        else
        {
            flag=1;
        }
    }
    if(flag)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}