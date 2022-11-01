#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char p[101];
        char h[101];
        scanf("%s%s",p,h);
        int n=strlen(p);
        int m=strlen(h);
        vector<int> a(26,0);
        for(int i=0;i<n;i++) a[p[i]-'a']++;
        vector<int> b(26,0);
        bool res=0;
        for(int i=0;i<min(n,m);i++) b[h[i]-'a']++;
        if(a==b) res=1;
        for(int i=n;i<m;i++)
        {
            b[h[i]-'a']++;
            b[h[i-n]-'a']--;
            if(a==b) res=1;
        }
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}