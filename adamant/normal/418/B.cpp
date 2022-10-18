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
const long long INF=3e18;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,b;
    cin>>n>>m>>b;
    const int MAXN=1<<m;
    int x[n],mi[n];
    long long k[n];
    int mask[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>k[i]>>mi[i];
        k[i]*=b;
        mask[i]=0;
        int t;
        for(int j=0;j<mi[i];j++)
            cin>>t,
            mask[i]+=1<<t-1;
    }


    for(int i=0;i<n;i++)
    for(int i=1;i<n;i++)
if(k[i]<k[i-1])
{
swap(k[i],k[i-1]);
swap(x[i],x[i-1]);
swap(mask[i],mask[i-1]);
}

    long long DP[MAXN];

    for(int i=0;i<MAXN;i++)
    DP[i]=INF;
    DP[0]=0;
    long long ans=INF;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<MAXN;j++)
        {
            int N=j|mask[i];
            long long old=DP[N];
            long long New=DP[j]+x[i];
            if(old > New)
                DP[N]=New;
        }
            ans=min(ans,DP[MAXN-1]+k[i]);
    }
    if(ans==INF)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}