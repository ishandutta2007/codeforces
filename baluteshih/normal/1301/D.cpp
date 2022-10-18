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

vector<pair<int,string>> step;

int main()
{
    IOS();
    int n,m,k,nw=1;
    cin >> n >> m >> k;
    if(k>4*n*m-2*n-2*m)
        return cout << "NO\n",0;
    while(k>0)
    {
        if(k>m-1)
        {
            k-=m-1;
            if(m>1) step.pb(make_pair(m-1,"R"));
        }
        else
        {
            if(k) step.pb(make_pair(k,"R")),k=0;
            break;
        }
        if(nw==n)
        {
            if(k>m-1)
            {
                k-=m-1;
                if(m>1) step.pb(make_pair(m-1,"L"));
            }
            else
            {
                if(k) step.pb(make_pair(k,"L")),k=0;
                break;
            }
            if(k) step.pb(make_pair(k,"U")),k=0;
            break;
        }
        else
        {
            if(k>3*(m-1))
            {
                k-=3*(m-1);
                if(m>1) step.pb(make_pair(m-1,"DUL"));
            }
            else
            {
                if(k/3>0) step.pb(make_pair(k/3,"DUL"));
                if(k%3==1) step.pb(make_pair(1,"D"));
                else if(k%3==2) step.pb(make_pair(1,"DU"));
                k=0;
                break;
            }
            if(k>1)
            {
                --k;
                step.pb(make_pair(1,"D"));
                ++nw;
            }
            else
            {
                k=0;
                step.pb(make_pair(1,"D"));
                break;
            }
        }
    }
    cout << "YES\n" << SZ(step) << "\n";
    for(auto i:step)
        cout << i.X << " " << i.Y << "\n";
}