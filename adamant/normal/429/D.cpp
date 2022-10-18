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
//
    int n;
    cin>>n;
    v(int) a(n);
    cin>>a;
    int mi=1e18;
    for(int i=1;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n && j-i+1<=1002;j++)
        {
            sum+=a[j];
            mi=min(mi,(j-i+1)*(j-i+1)+sum*sum);
        }
    }
    cout<<mi<<endl;
}