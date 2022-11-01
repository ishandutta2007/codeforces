#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[300001];
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        vector<int> v[2];
        for(int i=0;i<n;i++) v[(s[i]-'0')%2].push_back(s[i]-'0');
        for(int i=0;i<2;i++)
        {
            v[i].push_back(10);
            reverse(v[i].begin(),v[i].end());
        }
        for(int i=0;i<n;i++)
        {
            int a=(v[0].back()>v[1].back());
            printf("%d",v[a].back());
            v[a].pop_back();
        }
        printf("\n");
    }
    return 0;
}