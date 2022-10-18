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

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string a;
    cin>>a;
    int c=0;
    for(int i=0;i<n;i++)
        c+=a[i]=='x';
    bool mod=c>n-c;
    int k=abs(c-n/2);
    cout<<k<<endl;
    for(int i=0;i<n;i++)
        if(mod && a[i]=='x' && k)
            a[i]='X',k--;
        else if(!mod && a[i]=='X' && k)
            a[i]='x',k--;

    cout<<a<<endl;

}