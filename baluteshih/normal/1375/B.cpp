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

int arr[305][305];

int main()
{
    IOS();
    int t,n,m,mx;
    cin >> t;
    while(t--)
    {
        cin >> n >> m,mx=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin >> arr[i][j],mx=max(mx,arr[i][j]);
        if(arr[1][1]>2||arr[1][m]>2||arr[n][1]>2||arr[n][m]>2)
        {
            cout << "NO\n";
            continue;
        }
        int flag=1;
        for(int i=1;i<=n;++i)
            flag&=(arr[i][1]<=3&&arr[i][m]<=3);
        for(int i=1;i<=m;++i)
            flag&=(arr[1][i]<=3&&arr[n][i]<=3);
        flag&=(mx<=4);
        if(!flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                if(i==1||i==n)
                    if(j==1||j==m)
                        cout << 2;
                    else
                        cout << 3;
                else if(j==1||j==m)
                    if(i==1||i==n)
                        cout << 2;
                    else
                        cout << 3;
                else
                    cout << 4;
                cout << " \n"[j==m];
            }
    }
}