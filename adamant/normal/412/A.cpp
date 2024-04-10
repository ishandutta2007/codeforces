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
    int n,m;
    cin>>n>>m;
    string a;
    cin>>a;
    m--;
    int M=m;
    bool rev=0;
    string to[2]={"LEFT","RIGHT"};
    if(n-m-1<m)
    {
        reverse(all(a));
        rev=1;
        m=n-m-1;
        M=m;
    }
    while(m)
    {
        cout<<"PRINT "<<a[m]<<endl;
        cout<<to[rev]<<endl;
        m--;
    }
    cout<<"PRINT "<<a[m]<<endl;
    if(M!=n-1)
    while(m<=M)
    {
        cout<<to[!rev]<<endl;
        m++;
    }
    else
        return 0;
    while(m<n)
    {
        cout<<"PRINT "<<a[m]<<endl;
        if(m!=n-1)
        cout<<to[!rev]<<endl;
        m++;
    }
}