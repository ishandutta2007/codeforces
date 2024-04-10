#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> mask(n+1,0);
    int x=1;
    for(int m=0;m<(1<<13);m++) if(__popcount(m)==6&&x<=n) mask[x++]=m;
    vector<ll> q(13,0);
    for(int i=0;i<13;i++)
    {
        vector<int> v;
        for(int j=1;j<=n;j++) if((mask[j]&(1<<i))==0) v.push_back(j);
        if(!v.empty())
        {
            cout << "? " << v.size();
            for(int a:v) cout << " " << a;
            cout << "\n";
            cout.flush();
            cin >> q[i];
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++)
    {
        ll r=0;
        for(int j=0;j<13;j++) if(mask[i]&(1<<j)) r|=q[j];
        cout << r << " \n"[i==n];
    }
    cout.flush();
    return 0;
}