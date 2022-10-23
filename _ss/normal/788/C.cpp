#include <bits/stdc++.h>
#define conv(u) 1000+u
using namespace std;
const int N=1005;

int n, q, cnt[N], a[N], d[2*N];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>q>>n;
    while (n--) {
        int x; cin>>x;
        ++cnt[x];
    }
    n=0;
    for (int i=0; i<=1000; ++i) {
        if (cnt[i]) a[++n]=i-q;
    }

    for (int i=1; i<=n; ++i) {
        if (a[i]==0) {
            cout<<1;
            return 0;
        }
    }

    queue<int> q;
    fill(d, d+sizeof(d)/sizeof(int), -1);
    d[conv(0)]=0;
    q.emplace(0);
    while (!q.empty()) {
        int u=q.front(); q.pop();
        for (int i=1; i<=n; ++i) {
            int v=u+a[i];
            if (v==0) {
                cout<<d[conv(u)]+1;
                return 0;
            }
            if (-1000<=v && v<=1000 && d[conv(v)]==-1) {
                d[conv(v)]=d[conv(u)]+1;
                q.emplace(v);
            }
        }
    }
    cout<<-1;
    return 0;
}