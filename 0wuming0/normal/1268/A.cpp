#include"bits/stdc++.h"
using namespace std;
char s[200005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int flag=1;
    for(int j=k;j<n;j++)
    {
        int i=j-k;
        if(s[j]<s[i])flag=0;
        if(flag&&s[j]>s[i])
        {
            s[k-1]++;
            for(int p=k-1;s[p]=='9'+1;)
            {
                s[p]='0';
                s[--p]+=1;
            }
            goto nex;
        }
        s[j]=s[i];
    }
    nex:;
    for(int i=0;i<k;i++)
    {
        for(int j=i+k;j<n;j+=k)
        {
            s[j]=s[i];
        }
    }
    cout<<n<<endl;
    printf("%s\n",s);
    return 0;
}