#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    char s[200001];
    auto one=[&]()->vector<int>
    {
        s[0]='>';
        int now=n;
        vector<int> v(n);
        int idx=0;
        while(idx<n)
        {
            int cnt=0;
            for(int i=idx+1;i<n&&s[i]=='<';i++) cnt++;
            for(int i=0;i<cnt+1;i++) v[idx+i]=now-cnt+i;
            now-=(cnt+1);
            idx+=(cnt+1);
        }
        return v;
    };
    auto two=[&]()->vector<int>
    {
        s[0]='<';
        int now=1;
        vector<int> v(n);
        int idx=0;
        while(idx<n)
        {
            int cnt=0;
            for(int i=idx+1;i<n&&s[i]=='>';i++) cnt++;
            for(int i=0;i<cnt+1;i++) v[idx+i]=now+cnt-i;
            now+=(cnt+1);
            idx+=(cnt+1);
        }
        return v;
    };
    while(t--)
    {
        scanf("%d%s",&n,s+1);
        vector<int> a=one();
        vector<int> b=two();
        for(int i=0;i<n;i++) printf("%d%c",a[i]," \n"[i==n-1]);
        for(int i=0;i<n;i++) printf("%d%c",b[i]," \n"[i==n-1]);
    }
    return 0;
}