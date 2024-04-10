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
const int INF=2e9;

int check(int a,int b)
{
    if(a==b)return 0;
    if(a>b) return 2;
    if(a<b) return 1;
    return 42;
}

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    int T[3];
    cin>>T[0]>>T[1]>>T[2];
    v(v(int)) x(n,v(int)(m));
    cin>>x;

    int left[n][m];
    int right[n][m];
    int up[n][m];
    int down[n][m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(j)
                left[i][j]=left[i][j-1]+T[check(x[i][j],x[i][j-1])];
            else
                left[i][j]=0;
            if(j)
                right[i][j]=right[i][j-1]+T[check(x[i][j-1],x[i][j])];
            else
                right[i][j]=0;
            if(i)
                up[i][j]=up[i-1][j]+T[check(x[i][j],x[i-1][j])];
            else
                up[i][j]=0;
            if(i)
                down[i][j]=down[i-1][j]+T[check(x[i-1][j],x[i][j])];
            else
                down[i][j]=0;
        }

    int ax1,ay1,ax2,ay2;
    int md=INF;
    for(int i=0;i<n;i++)
    {
        for(int j=i+2;j<n;j++)
        {
            set<p(int,int)> pre;
            for(int k=1;k<m;k++)
            {
                if(k>1)
                {
                    int cur=right[i][k]+left[j][k]+down[j][k]-down[i][k];
                    auto it1=pre.upper_bound({t-cur,INF});
                    auto it2=it1;
                    --it2;
                    if(it1!=end(pre) && abs(cur+it1->first-t)<md)
                    {
                        md=abs(cur+it1->first-t);
                        ax1=i+1;
                        ay1=it1->second+1;
                        ax2=j+1;
                        ay2=k+1;
                    }

                    if(abs(cur+it2->first-t)<md)
                    {
                        md=abs(cur+it2->first-t);
                        ax1=i+1;
                        ay1=it2->second+1;
                        ax2=j+1;
                        ay2=k+1;
                    }
                }
                pre.insert({up[j][k-1]-up[i][k-1]-right[i][k-1]-left[j][k-1],k-1});
            }
        }
    }
    cout<<ax1<<' '<<ay1<<' '<<ax2<<' '<<ay2<<endl;
}