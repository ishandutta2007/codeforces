#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>
#define int long long


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<" "<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

const int MOD=1e9+7;

main()
{
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    v(int) P(n);
    cin>>P;

    v(int) DP(n);
    v(int) pre(n+1,0);
    DP[0]=2;
    pre[1]=2;
    for(int i=1;i<n;i++)
    {
        if(P[i]==i+1)
            DP[i]=2;
        else
            DP[i]=(2+pre[i]-pre[P[i]-1])%MOD;
            if(DP[i]<0)DP[i]+=MOD;
        pre[i+1]=(pre[i]+DP[i])%MOD;
    }
    cout<<pre[n]<<endl;
}