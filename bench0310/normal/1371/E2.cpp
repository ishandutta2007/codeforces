#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin >> n >> p;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    for(auto [a,f]:m)
    {
        if(f>=p)
        {
            cout << "0\n";
            return 0;
        }
    }
    vector<int> res;
    int l=0,r=p-1;
    int nxt=-1;
    int cnt=n;
    for(auto it=m.rbegin();it!=m.rend();it++)
    {
        auto [a,f]=(*it);
        if(nxt==-1)
        {
            nxt=a;
            cnt-=f;
            r-=f;
            continue;
        }
        //cout << "in a=" << a << " f=" << f << endl;
        //cout << "l=" << l << " r=" << r << endl;
        if(cnt<p) for(int i=max(a,l-cnt+nxt);i<=min(nxt-1,r-cnt+nxt);i++) res.push_back(i);
        l=max(0,l+nxt-a-f);
        r=min(p-1-f,r+nxt-a-f);
        nxt=a;
        cnt-=f;
    }
    sort(res.begin(),res.end());
    cout << res.size() << "\n";
    for(int x:res) cout << x << " ";
    cout << "\n";
    return 0;
}