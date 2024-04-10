#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        v[i]={a[i],i};
    }
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    b.push_back(1<<30);
    auto out=[](){cout << "0\n"; exit(0);};
    if(n<m) out();
    sort(v.begin(),v.end());
    if(v[0][0]<b[0]) out();
    vector<int> l(m,0);
    vector<int> r(m,0);
    int idx=0;
    for(int i=0;i<m;i++)
    {
        while(i>0&&idx<n&&v[idx][1]<=r[i-1]) idx++;
        if(idx==n||v[idx][0]!=b[i]) out();
        while(idx<n&&v[idx][0]<b[i+1])
        {
            if(v[idx][0]==b[i]) l[i]=max(l[i],v[idx][1]);
            r[i]=max(r[i],v[idx][1]);
            idx++;
        }
    }
    l[0]=0;
    r[m-1]=n-1;
    for(int i=0;i<m-1;i++) if(r[i]>=l[i+1]) out();
    ll res=1;
    for(int i=0;i<m-1;i++) res=(res*(l[i+1]-r[i]))%mod;
    cout << res << "\n";
    return 0;
}