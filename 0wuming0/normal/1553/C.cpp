#include"bits/stdc++.h"
using namespace std;
char s[14];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a=0,b=5,c=0,d=5,e=0,e2=0;
        scanf("%s",s);
        for(int i=0;i<10;i++)
        {
            if(i&1)
            {
                if(s[i]=='1')
                {
                    a++;
                }
                else if(s[i]=='0')
                {
                    b--;
                }
                else e++;
            }
            else
            {
                if(s[i]=='1')
                {
                    c++;
                }
                else if(s[i]=='0')
                {
                    d--;
                }
                else e2++;
            }
            if(a+e>d-e2||c+e2>b-e)
            {
                printf("%d\n",i+1);
                goto ne;
            }
        }
        printf("10\n");
        ne:;
    }
    return 0;
}