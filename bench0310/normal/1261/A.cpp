#include <bits/stdc++.h>

using namespace std;

char s[2005];

bool one(int n,int k,int i)
{
    if(i<2*(k-1)) return (!(i&1));
    else return (i<2*(k-1)+(n-2*(k-1))/2);
}

void rev(int l,int r)
{
    char t[r-l+5];
    for(int i=0;i+l<=r;i++) t[i]=s[i+l];
    for(int i=0;r-i>=l;i++) s[r-i]=t[i];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        vector<pair<int,int>> v;
        for(int o=0;o<n;o++)
        {
            if(one(n,k,o)==1&&s[o]==')')
            {
                int idx=0;
                for(int i=o+1;i<n;i++) if(s[i]=='(') idx=i;
                rev(o,idx);
                v.push_back({o+1,idx+1});
            }
            if(one(n,k,o)==0&&s[o]=='(')
            {
                int idx=0;
                for(int i=o+1;i<n;i++) if(s[i]==')') idx=i;
                rev(o,idx);
                v.push_back({o+1,idx+1});
            }
        }
        printf("%d\n",(int)v.size());
        for(pair<int,int> p:v) printf("%d %d\n",p.first,p.second);
    }
    return 0;
}