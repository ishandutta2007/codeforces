#include"bits/stdc++.h"
using namespace std;
char s[100005];
int ans[100005],nn;
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    int p=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==')')p++;
        else if(s[i]=='(')
        {
            if(s[i]=='(')p--;
            if(p<0)
            {
                if(nn)
                {
                    ans[nn-1]++;
                    p++;
                }
                else
                {
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        else
        {
            if(nn>0&&ans[nn-1]==0)ans[nn-1]++,p++;
            nn++;
        }
    }
    int flag=1;
    for(int i=0;i<nn;i++)if(ans[i]==0)flag=0;
    if(flag&&p==0)
    {
        for(int i=nn-1;i>=0;i--)printf("%d\n",ans[i]);
        //
    }
    else cout<<-1<<endl;
    return 0;
}