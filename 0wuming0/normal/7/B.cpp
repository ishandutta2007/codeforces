#include"bits/stdc++.h"
using namespace std;
int now=1;
char c[100];
int s[105];
int ans[105];
int main()
{
    int t,m;
    cin>>t>>m;
    while(t--)
    {//for(int i=0;i<m;i++)cout<<ans[i];cout<<endl;
        scanf("%s",c);
        if(c[0]=='d')
        {
            int num=0;
            for(int i=0;i<m;i++)
            {
                if(ans[i])
                {
                    int pp=ans[i];
                    ans[i]=0;
                    ans[num]=pp;
                    num++;
                }
            }
        }
        else
        {
            long long x;
            cin>>x;
            if(c[0]=='e')
            {
                if(x>=now||x<=0)
                {
                    cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
                }
                else
                {
                    int flag=1;
                    for(int i=0;i<m;i++)if(ans[i]==x)
                    {
                        ans[i]=0;
                        flag=0;
                    }
                    if(flag)cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
                }

            }
            else
            {
                int num=0;
                for(int i=0;i<m;i++)
                {
                    if(!ans[i])
                    {
                        num++;
                        if(num==x)
                        {
                            cout<<now<<endl;
                            while(num--)
                            {
                                ans[i]=now;
                                i--;
                            }
                            now++;
                            break;
                        }
                    }
                    else num=0;
                    if(i==m-1)
                    {
                        cout<<"NULL"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}