#include <bits/stdc++.h>

using namespace std;

long long n, k, ki, h, hh;
int d[100001], dg[100001], apa[100001];
bool volt[100001];
vector<int> g[100001];
bool good=true;

void mely(int a) {
    volt[a]=true;
    for(int i=0;i<g[a].size();i++) {
        if(volt[g[a][i]]) continue;
        d[g[a][i]]=d[a]+1;
        apa[g[a][i]]=a;
        mely(g[a][i]);
    }
}

int md(int a) {
    for(int i=1;i<=n;i++) volt[i]=false;
    d[a]=0;
    apa[a]=a;
    mely(a);
    int maxd=1;
    for(int i=2;i<=n;i++) {
        if(d[i]>d[maxd]) maxd=i;
    }
    return maxd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if(k>n) k=n;
    for(int i=0;i<n-1;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        dg[a]++;
        dg[b]++;
    }
    for(int i=1;i<=n;i++) {
        if(dg[i]==2) good=false;
        if(dg[i]==3) {
            h++;
            hh=i;
        }
    }
    if(h>1) good=false;
    if(h==0) {
        int a=md(1);
        int b=md(a);
        for(int i=0;i<k;i++) b=apa[b];
        hh=b;
    }
    if(h<=1) {
        int a=md(hh);
        if(d[a]!=k) good=false;
        for(int i=1;i<=n;i++) {
            if(dg[i]>1) continue;
            if(d[i]==k) continue;
            good=false;
        }
    }
    if(good) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}