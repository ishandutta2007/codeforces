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

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    v(v(int)) a(n,v(int)(m));
    cin>>a;

    v(v(int)) DP[4];
    DP[0]=DP[1]=DP[2]=DP[3]=a;

    for(int i=1;i<n;i++)
        DP[0][i][0]+=DP[0][i-1][0],
        DP[3][i][m-1]+=DP[3][i-1][m-1],
        DP[1][n-i-1][m-1]+=DP[1][n-i][m-1],
        DP[2][n-i-1][0]+=DP[2][n-i][0];
    for(int i=1;i<m;i++)
        DP[0][0][i]+=DP[0][0][i-1],
        DP[2][n-1][i]+=DP[2][n-1][i-1],
        DP[1][n-1][m-i-1]+=DP[1][n-1][m-i],
        DP[3][0][m-i-1]+=DP[3][0][m-i];

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            DP[0][i][j]+=max(DP[0][i-1][j],DP[0][i][j-1]),
            DP[1][n-i-1][m-j-1]+=max(DP[1][n-i][m-j-1],DP[1][n-i-1][m-j]),
            DP[2][n-i-1][j]+=max(DP[2][n-i][j],DP[2][n-i-1][j-1]),
            DP[3][i][m-j-1]+=max(DP[3][i-1][m-j-1],DP[3][i][m-j]);

    int mx=0;
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
            mx=max(mx,DP[0][i][j-1]+DP[1][i][j+1]+DP[2][i+1][j]+DP[3][i-1][j]),
            mx=max(mx,DP[0][i-1][j]+DP[1][i+1][j]+DP[2][i][j-1]+DP[3][i][j+1]);

    cout<<mx<<endl;

}