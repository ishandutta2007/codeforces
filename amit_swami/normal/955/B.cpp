#include<bits/stdc++.h>
using namespace std;

char s[200000];
map<char,int> m;

signed main()
{
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;++i) m[s[i]]++;
    int ok=-1;
    if(n<=3||m.size()==1) ok=0;
    else if(m.size()==4) ok=1;
    else if(m.size()==3) ok=1;
    else if(m.size()>4) ok=0;
    else if(m.size()==2)
    {
        int x=n;
        for(auto z:m) x=min(x,z.second);
        if(x<=1) ok=0;
        else ok=1;
    }
    if(ok) printf("Yes\n");
    else printf("No\n");

    return 0;
}