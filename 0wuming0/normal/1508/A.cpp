#include"bits/stdc++.h"
using namespace std;
char s1[200005],s2[200005],s3[200005];
char ans[300005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        scanf("%s%s%s",s1,s2,s3);
        nn=0;
        int a=0,b=0,c=0;
        while(a!=n*2&&b!=n*2&&c!=n*2)
        {
            int k[2]={0};
            k[s1[a]-'0']++;
            k[s2[b]-'0']++;
            k[s3[c]-'0']++;
            if(k[0]>1)ans[nn]='0';
            else ans[nn]='1';
            if(ans[nn]==s1[a])a++;
            if(ans[nn]==s2[b])b++;
            if(ans[nn]==s3[c])c++;
            nn++;
        }
        if(a!=n*2&&n*2-a+nn<=3*n)for(int i=a;s1[i];i++)ans[nn++]=s1[i];
        if(b!=n*2&&n*2-b+nn<=3*n)for(int i=b;s2[i];i++)ans[nn++]=s2[i];
        if(c!=n*2&&n*2-c+nn<=3*n)for(int i=c;s3[i];i++)ans[nn++]=s3[i];
        while(nn!=n*3)ans[nn++]='0';
        ans[nn]=0;
        printf("%s\n",ans);
    }
    return 0;
}