#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<array<ll,2>> v(1);
    cin >> v[0][0] >> v[0][1];
    ll ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    ll x,y,t;
    cin >> x >> y >> t;
    const ll lim=20000000000000000;
    while(ax*v.back()[0]+bx<=lim&&ay*v.back()[1]+by<=lim)
    {
        v.push_back({ax*v.back()[0]+bx,ay*v.back()[1]+by});
    }
    int res=0;
    int n=v.size();
    vector<ll> d(n,0);
    for(int i=0;i<n-1;i++) d[i]=(v[i+1][0]-v[i][0]+v[i+1][1]-v[i][1]);
    for(int i=0;i<n;i++)
    {
        if(abs(x-v[i][0])+abs(y-v[i][1])>t) continue;
        ll c=t-abs(x-v[i][0])-abs(y-v[i][1]);
        int now=1;
        for(int j=i-1;j>=0;j--)
        {
            if(c>=d[j])
            {
                c-=d[j];
                now++;
            }
            else break;
        }
        res=max(res,now);
        c=t-abs(x-v[i][0])-abs(y-v[i][1]);
        now=1;
        for(int j=i;j<n-1;j++)
        {
            if(c>=d[j])
            {
                c-=d[j];
                now++;
            }
            else break;
        }
        res=max(res,now);
    }
    cout << res << "\n";
    return 0;
}