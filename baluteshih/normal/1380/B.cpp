#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

string s;

int main()
{
    IOS();
    int t;
    cin >> t;
    while(t--)
    {
        int cnt[3]={};
        cin >> s;
        for(char c:s)
            if(c=='R')
                ++cnt[0];
            else if(c=='S')
                ++cnt[1];
            else
                ++cnt[2];
        int p=max_element(cnt,cnt+3)-cnt;
        if(p==0)
            cout << string(SZ(s),'P') << "\n";
        else if(p==1)   
            cout << string(SZ(s),'R') << "\n";
        else
            cout << string(SZ(s),'S') << "\n";
    }
}