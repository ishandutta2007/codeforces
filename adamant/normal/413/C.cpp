#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<" "<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

const int INF=1e9;
#define int long long
main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    v(p(int,int)) cost(n,{0,0});
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>cost[i].second;
        cost[i].second=-cost[i].second;
    }
    for(int i=0;i<m;i++)
    {
        cin>>t;
        cost[t-1].first=1;
    }
    sort(all(cost));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cost[i].first)
            ans+=max(ans,-cost[i].second);
        else
            ans+=-cost[i].second;
    }
    cout<<ans<<endl;
}