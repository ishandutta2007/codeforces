#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<long long> a(n+3),pre(n+3);
    vector<vector<vector<int> > > occ(2,vector<vector<int>>(n+3,vector<int>()));
    //map<long long,vector<int>> idx;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pre[i]=a[i]-pre[i-1];
    }

    vector<long long> values;
    for (int i=0;i<=n;i++) values.push_back(pre[i]);
    sort(values.begin(),values.end());
    values.resize(unique(values.begin(),values.end())-values.begin());

    map<long long,int> m;
    int nn=values.size();
    for (int i=0;i<nn;i++) m[values[i]]=i+1;

    for (int i=0;i<=n;i++)
        occ[i&1][m[pre[i]]].push_back(i);

    vector<pair<long long,int>> stk[2];
    pre[n+1]=pre[n+2]=-1e18;
    stk[(n+1)&1].push_back({-1e18,n+1});
    stk[(n+2)&1].push_back({-1e18,n+2});

    long long ans=0;

    for (int i=n;i>=0;i--) {
        int ridx1= (*prev(lower_bound(stk[i&1].begin(),stk[i&1].end(),make_pair(pre[i],-1)))).second;
        int ridx2= (*prev(lower_bound(stk[i&1^1].begin(),stk[i&1^1].end(),make_pair(-pre[i],-1)))).second;
        int r=min({n,ridx1-1,ridx2-1});

        int idx1=m[pre[i]],idx2=m[-pre[i]];

        ans+=upper_bound(occ[i&1][idx1].begin(),occ[i&1][idx1].end(),r)
            -lower_bound(occ[i&1][idx1].begin(),occ[i&1][idx1].end(),i+1);
        ans+=upper_bound(occ[i&1^1][idx2].begin(),occ[i&1^1][idx2].end(),r)
            -lower_bound(occ[i&1^1][idx2].begin(),occ[i&1^1][idx2].end(),i+1);

        while (stk[i&1].back().first>=pre[i]) stk[i&1].pop_back();
        stk[i&1].push_back(make_pair(pre[i],i));
    }
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) solve();
}