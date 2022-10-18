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

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int l=-1e9-1,r=1e9+1;
    string a;
    int num;
    char c;
    for(int i=0;i<n;i++)
    {
        cin>>a>>num>>c;
        if(c=='Y')
        {
        if(a==">")
            l=max(l,num+1);
        if(a==">=")
            l=max(l,num);
        if(a=="<")
            r=min(r,num-1);
        if(a=="<=")
            r=min(r,num);
        }
        else
        {
        if(a==">")
            r=min(r,num);
        if(a==">=")
            r=min(r,num-1);
        if(a=="<")
            l=max(l,num);
        if(a=="<=")
            l=max(l,num+1);
        }
    }
    if(l<=r)
        cout<<l<<endl;
    else
        cout<<"Impossible"<<endl;
}