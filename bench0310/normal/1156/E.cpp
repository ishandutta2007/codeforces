#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1,0);
    vector<int> pos(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
        pos[p[i]]=i;
    }
    int res=0;
    set<int> s={0,n+1};
    for(int i=n;i>=1;i--)
    {
        auto it=s.lower_bound(pos[i]);
        int r=*it;
        it--;
        int l=*it;
        s.insert(pos[i]);
        if(pos[i]-l<r-pos[i]) for(int j=l+1;j<pos[i];j++) res+=(pos[i]<pos[i-p[j]]&&pos[i-p[j]]<r);
        else for(int j=pos[i]+1;j<r;j++) res+=(l<pos[i-p[j]]&&pos[i-p[j]]<pos[i]);
    }
    cout << res << "\n";
    return 0;
}