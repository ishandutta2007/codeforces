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
    map<char,int> to;
    to['R']=0;to['G']=1;to['B']=2;
    to['Y']=3;to['W']=4;
    vector<string> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    sort(begin(x),end(x));
    x.resize(unique(begin(x),end(x))-begin(x));
    n=x.size();
    int ans=10;
    for(int i=0;i<(1<<5);i++)
        for(int j=0;j<(1<<5);j++)
        {
            bitset<5> z=i,y=j;
            int cur=__builtin_popcount(i)+__builtin_popcount(j);
            vector<int> blind(10,0);
            int gl_blind=0;
            for(int k=0;k<n;k++)
            {
                int a=to[x[k][0]],b=x[k][1]-'1';
                gl_blind+=!(z[a]|y[b]);
                blind[a]+=z[a] && !y[b];
                blind[b+5]+=y[b] && !z[a];
            }
            bool ok=gl_blind<=1;
            for(int i=0;i<10;i++)
                if(blind[i]>=2) ok=0;
            if(ok) ans=min(ans,cur);
        }
    cout<<ans<<endl;
}