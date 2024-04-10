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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    map<char,int> ok;
    ok['A']=1;
    ok['H']=1;
    ok['O']=1;
    ok['Y']=1;
    ok['X']=1;
    ok['M']=1;
    ok['T']=1;
    ok['U']=1;
    ok['V']=1;
    ok['W']=1;
    ok['I']=1;
    bool Ok=1;
    for(int i=0;i<n/2+n%2;i++)
        if(a[i]!=a[n-i-1] || !ok[a[i]])Ok=0;

    cout<<(Ok?"YES":"NO")<<endl;

}