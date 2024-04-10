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

#define TASK "test"

int try_(v(p(int,int)) a,v(p(int,int)) b,int t,int h)
{
    int c_x=0,c_y=0;
    multiset<int> x,y;
    int cur=0;
    while(not false)
    {
        if(t)
        {
            for(;c_x<a.size() && a[c_x].first<=h;c_x++) x.insert(a[c_x].second);
            if(x.empty()) break;
            auto it=--x.end();
            h+=*it;
            x.erase(it);
            cur++;
        }
        else
        {
            for(;c_y<b.size() && b[c_y].first<=h;c_y++) y.insert(b[c_y].second);
            if(y.empty()) break;
            auto it=--y.end();
            h+=*it;
            y.erase(it);
            cur++;
        }
        t=!t;
    }
    return cur;
}

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    v(p(int,int)) a,b;
    for(int i=0;i<n;i++)
    {
        int t,h,m;
        cin>>t>>h>>m;
        if(t) a.push_back({h,m});
        else b.push_back({h,m});
    }
    sort(all(a));
    sort(all(b));
    int ans=max(try_(a,b,0,x),try_(a,b,1,x));
    cout<<ans<<endl;
}