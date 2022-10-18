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
    int n,m,mi,ma;
    cin>>n>>m>>mi>>ma;
    int mix=INF,man=-INF;
    int t;
    for(int i=0;i<m;i++)
    {
        cin>>t;
        mix=min(mix,t);
        man=max(man,t);
    }
    if(mix>=mi && man<=ma)
        if(mix==mi || man==ma || n-m>=2)
    {cout<<"Correct"<<endl;return 0;}
        cout<<"Incorrect"<<endl;

}