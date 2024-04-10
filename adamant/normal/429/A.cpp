#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<' '<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

#define int long long

const int INF=1e9;

v(v(int)) G;

v(int) init;
v(int) goal;

v(int) used;
v(int) ans;

void dfs(int x,int h,v(int) cnt)
{
    used[x]=1;
    if(init[x]^cnt[h&1]!=goal[x])
        cnt[h&1]^=1,
        ans.push_back(x+1);
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i]]) dfs(G[x][i],h+1,cnt);
}

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    G.resize(n);
    int u,v;
    for(int i=0;i<n-1;i++)
        cin>>u>>v,
        G[u-1].push_back(v-1),
        G[v-1].push_back(u-1);
    init.resize(n);
    goal.resize(n);
    used.assign(n,0);
    cin>>init>>goal;
    dfs(0,0,{0,0});
    cout<<ans.size()<<endl;
    cout<<ans<<endl;

}