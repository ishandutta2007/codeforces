#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    char s[n+1];
    scanf("%s\n",s);
    s[n]='{';
    vector<bool> v(27,0);
    for(int i=0;i<k;i++)
    {
        char a;
        scanf("%c%*c",&a);
        v[a-'a']=1;
    }
    long long res=0;
    long long cnt=0;
    for(int i=0;i<=n;i++)
    {
        if(v[s[i]-'a']) cnt++;
        else
        {
            res+=(cnt*(cnt+1)/2);
            cnt=0;
        }
    }
    printf("%I64d\n",res);
    return 0;
}