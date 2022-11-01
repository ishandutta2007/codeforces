#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=20000;
    int t;
    cin >> t;
    set<int> d[N+1];
    for(int o=1;o<=N;o++)
    {
        for(int i=1;i*i<=o;i++)
        {
            if((o%i)>0) continue;
            d[o].insert(i);
            if(i*i!=o) d[o].insert(o/i);
        }
    }
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int best=(1<<30);
        array<int,3> res;
        for(int x=1;x<=N;x++)
        {
            set<int> &one=d[x];
            auto it=one.lower_bound(a);
            int z=(1<<30);
            int val;
            if(it!=one.end())
            {
                z=min(z,abs((*it)-a));
                val=(*it);
            }
            if(it!=one.begin())
            {
                it--;
                if(abs((*it)-a)<z) val=(*it);
                z=min(z,abs((*it)-a));
            }
            int now=abs(x-b)+z+min(c%x,x-c%x);
            if(now<best)
            {
                best=now;
                res[0]=val;
                res[1]=x;
                if((c%x)<(x-c%x)) res[2]=c-c%x;
                else res[2]=c+(x-c%x);
            }
        }
        cout << best << "\n";
        for(int i=0;i<3;i++) cout << res[i] << " \n"[i==2];
    }
    return 0;
}