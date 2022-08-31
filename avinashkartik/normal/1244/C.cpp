#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
    int main() {
     
        ll n, p, w, d;
        cin>>n>>p>>w>>d;
     
        const int N = 1e5;
        for (ll x = 0; x<=N; x++)
        {
            if ((p - x*w)%d==0)
            {
                ll y = (p-x*w)/d;
                if (y>=0 && x+y<=n)
                {
                    cout<<x<<' '<<y<<' '<<n-x-y; return 0;
                }
            }
        }
     
     
        for (ll y = 0; y<=N; y++)
        {
            if ((p - y*d)%w==0)
            {
                ll x = (p-y*d)/w;
                if (x>=0 && x+y<=n)
                {
                    cout<<x<<' '<<y<<' '<<n-x-y; return 0;
                }
            }
        }
     
        cout<<-1<<endl;
     
    }