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

const int INF=1e9;
int arr[1005],mil[1005],mir[1005];

int main() 
{
    IOS();
    int t,n,flag;
    cin >> t;
    while(t--)
    {
        cin >> n,mil[0]=mir[n+1]=0,arr[0]=INF;
        for(int i=1;i<=n;++i)
            cin >> arr[i];
        for(int i=1;i<=n;++i)
            if(arr[i]<arr[mil[i-1]])
                mil[i]=i;
            else
                mil[i]=mil[i-1];
        for(int i=n;i>=1;--i)
            if(arr[i]<arr[mir[i+1]])
                mir[i]=i;
            else
                mir[i]=mir[i+1];
        flag=0;
        for(int i=2;i<n&&!flag;++i)
            if(arr[i]>arr[mil[i-1]]&&arr[i]>arr[mir[i+1]])
            {
                flag=1;
                cout << "YES\n";
                cout << mil[i-1] << " " << i << " " << mir[i+1] << "\n";
            }
        if(!flag)
            cout << "NO\n";
    }
}