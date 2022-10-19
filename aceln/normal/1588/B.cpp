#include <bits/stdc++.h>
using namespace std;

long long ask(int x) {
    cout<<"? " << 1 << ' ' << x <<endl;
    long long ans; cin>>ans;
    return ans;
}

void solve() {
    int n; cin>>n;
    int L=1, R=n;
    int i,j,k;

    long long total = ask(n);
    while (R-L>1) {
        int M = (L+R)>>1;
        if (ask(M)!=total) L=M;
        else R=M;
    }

    k = R;
    long long right_len=total-ask(L);
    j = k-right_len;

    long long left_len=ask(j-1)-ask(j-2);
    i = j-1-left_len;

    cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while (t--) solve();
}