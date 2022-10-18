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
if(n==1)
{
    if(k==0)
        cout<<1<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
    int t=k-n/2+1;
    if(t<1)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<t<<' '<<t*2<<endl;
    for(int i=2;i<n-(n&1);i+=2)
    {
        cout<<2*t+i+1<<' '<<2*t+i+2<<endl;
    }
    if(n&1)
        cout<<1000000000;


}