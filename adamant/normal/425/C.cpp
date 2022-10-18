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

const int INF=1e9;
#define int long long
main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,e;
    cin>>n>>m>>s>>e;
    v(int) a(n);
    v(int) b(m);
    cin>>a>>b;

    v(p(int,int)) data;
    for(int i=0;i<n;i++)
        data.push_back({a[i],i});
    sort(all(data));
    int k=s/e;
    v(v(int)) DP(m+1,v(int)(k+1,-1));

    int ans=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            auto it=upper_bound(all(data),make_pair(b[i],DP[i][j]));
            if((DP[i][j]!=-1 && DP[i][j]<DP[i+1][j]) || DP[i+1][j]==-1)DP[i+1][j]=DP[i][j];
            if(j && DP[i][j]==-1)break;
            if(it==data.end())continue;
            if(it->first!=b[i])continue;
            if(s-e*(j+1)<0)break;
            DP[i+1][j+1]=it->second;
            if(s-e*(j+1)-(i+1)-(it->second+1)>=0)
            ans=max(ans,j+1);
        }
    }

    cout<<ans<<endl;

}