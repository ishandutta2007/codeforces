#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string x[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    for(int i=0;i<8;i++)
    {
        if(x[i].size()!=n) continue;
        bool ok=1;
        for(int j=0;j<n;j++) if(s[j]!='.' && x[i][j]!=s[j]) ok=0;
        if(ok)
        {
            cout<<x[i]<<endl;
            return 0;
        }
    }

 }