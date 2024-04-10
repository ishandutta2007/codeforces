#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char s[n+1];
        scanf("%s",s);
        bool eq=1;
        char a[n+1];
        char b[n+1];
        a[n]=b[n]='\0';
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') a[i]=b[i]='0';
            else if(s[i]=='1')
            {
                if(eq)
                {
                    a[i]='1';
                    b[i]='0';
                    eq=0;
                }
                else
                {
                    a[i]='0';
                    b[i]='1';
                }
            }
            else if(s[i]=='2')
            {
                if(eq) a[i]=b[i]='1';
                else
                {
                    a[i]='0';
                    b[i]='2';
                }
            }
        }
        printf("%s\n%s\n",a,b);
    }
    return 0;
}