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

const int MOD=1e9+7;
const int INF=1e9;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;

    v(v(int)) DP(n+1,v(int)(k+1,0));

    for(int i=1;i<=n;i++)
        DP[i][1]=1;
    for(int j=1;j<k;j++)
        for(int i=1;i<=n;i++)
            for(int t=1;t*i<=n;t++)
        DP[i*t][j+1]=(DP[i*t][j+1]+DP[i][j])%MOD;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+DP[i][k])%MOD;
    cout<<ans<<endl;


}