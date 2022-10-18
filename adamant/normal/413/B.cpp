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

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    v(v(int)) a(n,v(int)(m));
    cin>>a;

    v(int) msg(m,0);
    v(int) mi(n,0);
    int x,y;
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        msg[y-1]++;
        mi[x-1]++;
    }

    for(int i=0;i<n;i++)
    {
        int cur=-mi[i];
        for(int j=0;j<m;j++)
            cur+=msg[j]*a[i][j];
        cout<<cur<<' ';
    }

}