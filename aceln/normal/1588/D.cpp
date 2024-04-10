#include <bits/stdc++.h>
using namespace std;

string s[11];
vector<int> occ[11][55];
vector<int> G[54000];
int len[11];
int have[11][55];

string t="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int change[200];

int trans(int x,int y,int n){
    return (1<<n)*x+y;
}

void solve() {
    memset(have,0,sizeof(have));

    int n; cin>>n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<52;j++) occ[i][j].clear();

    }
    for (int i=0;i<52;i++) {
        for (int j=0;j<(1<<n);j++) G[i*(1<<n)+j].clear();
    }

    for (int i=0;i<n;i++) {
        cin>>s[i];
        len[i]=s[i].length();
        for (int j=0;j<len[i];j++) {
            occ[i][change[s[i][j]]].push_back(j);
            have[i][change[s[i][j]]]=1;
        }
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<52;j++)
            if ((int)occ[i][j].size()==1)
                occ[i][j].push_back(occ[i][j].back());


    vector<int> indeg((1<<n)*52+7),dp((1<<n)*52+7),las((1<<n)*52+7);

    vector<int> valid(55);
    for (int i=0;i<52;i++) {
        int tmp=0;
        for (int j=0;j<n;j++) tmp+=have[j][i];

        if (tmp==n) valid[i]=1;
    }


    for (int i=0;i<52;i++) {
        if (!valid[i]) continue;
        for (int j=0;j<(1<<n);j++) {
            vector<int> oc;
            for (int k=0;k<n;k++) oc.push_back(occ[k][i][(j>>k)&1]);

            for (int k=0;k<52;k++) {
                if (!valid[k]) continue;
                int next_state=0;
                for (int l=n-1;l>=0;l--) {
                    int tmpidx=upper_bound(occ[l][k].begin(),occ[l][k].end(),oc[l])-occ[l][k].begin();
                    if (tmpidx==2) {
                        next_state=-1;
                        break;
                    }
                    next_state=((next_state<<1)|tmpidx);
                }

                if (next_state!=-1) {
                    G[trans(i,j,n)].push_back(trans(k,next_state,n));
                    indeg[trans(k,next_state,n)]++;
                }
            }
        }
    }

    queue<int> q;
    for (int i=0;i<(1<<n)*52;i++) {
        if (valid[i/(1<<n)] && indeg[i]==0) q.push(i);
    }

    int max_len=-1,end_idx=-1;
    while (!q.empty()) {
        int now=q.front();
        q.pop();

        if (dp[now] > max_len) max_len=dp[now],end_idx=now;

        for (int i:G[now]) {
            if (dp[i] < dp[now] + 1) {
                dp[i] = dp[now] + 1;
                las[i] = now;
            }
            indeg[i]--;
            if (indeg[i]==0) q.push(i);
        }
    }

    string ans;
    cout<<max_len+1<<'\n';
    for (int j=0;j<=max_len;j++) {
        ans.push_back(t[end_idx/(1<<n)]);
        end_idx=las[end_idx];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<52;i++) change[t[i]]=i;
    int _; cin>>_;
    while (_--) solve();
}