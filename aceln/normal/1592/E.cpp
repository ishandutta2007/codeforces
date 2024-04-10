#include <bits/stdc++.h>
using namespace std;

int lasodd[(1<<20)+7],laseven[(1<<20)+7];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (int &i:a) cin>>i;

    int ans=0;

    for (int j=1;j<=20;j++) {
        int L=-1;
        if ((a[0]&1)) L=0;
        memset(lasodd,-1,sizeof(lasodd));
        memset(laseven,-1,sizeof(laseven));

        // for (int i:a) cout<<i<<' ';
        // cout<<'\n';

        int xorsum=0;
        for (int i=0;i<n;i++) {
            xorsum^=a[i];
            if (a[i]&1) {
                if (i&1) {
                    if (laseven[xorsum]>=L) ans=max(ans,i-laseven[xorsum]+1);
                    if (lasodd[xorsum^a[i]]<L) lasodd[xorsum^a[i]]=i;
                } else {
                    if (lasodd[xorsum]>=L) ans=max(ans,i-lasodd[xorsum]+1);
                    if (laseven[xorsum^a[i]]<L) laseven[xorsum^a[i]]=i;
                }
            }
            else {
                if (i+1<n&&(a[i+1]&1)) L=i+1;
            }
        }

        for (int &i:a) i>>=1;
    }
    cout<<ans<<'\n';
}