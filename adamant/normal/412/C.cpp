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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    v(string) a(n);
    cin>>a;
    int m=a[0].size();
    string ans(m,'#');
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(a[i][j]=='?')
            continue;
        if(ans[j]!=a[i][j])
        {
            if(ans[j]!='#')
                ans[j]='?';
            else
                ans[j]=a[i][j];
        }
    }
    for(int i=0;i<m;i++)
        if(ans[i]=='#')
            ans[i]='a';
    cout<<ans<<endl;
}