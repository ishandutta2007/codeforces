#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    vector<array<int,2>> v;
    for(int i=0;i<3;i++)
    {
        int r=3*i;
        int c=i;
        for(int j=0;j<3;j++) v.push_back({r+j,c+3*j});
    }
    while(t--)
    {
        char s[9][10];
        for(int o=0;o<9;o++) scanf("%s",s[o]);
        for(auto [a,b]:v)
        {
            if(s[a][b]=='1') s[a][b]='2';
            else s[a][b]='1';
        }
        for(int o=0;o<9;o++) printf("%s\n",s[o]);
    }
    return 0;
}