#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int dp[300 * 1000 + 10][2];

int main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    piii L[m];
    for (int i=0; i<m; i++){
        cin>>L[i].second.second>>L[i].second.first>>L[i].first;
    }
    sort(L, L+m);
    int u, v, w, lw=0, tmp;
    stack<int> X;
    for (int i=0; i<m; i++){
        u=L[i].second.second;
        v=L[i].second.first;
        w=L[i].first;
        //cout<<u<<' '<<v<<' '<<w<<endl;
        if (w==lw){
            dp[v][1]=max(max(dp[v][0], dp[v][1]), dp[u][0]+1);
            X.push(v);
        }
        else{
            lw=w;
            i--;
            while (!X.empty()){
                tmp=X.top();
                dp[tmp][0]=dp[tmp][1];
                X.pop();
            }
        }
    }
    while (!X.empty()){
        tmp=X.top();
        dp[tmp][0]=dp[tmp][1];
        X.pop();
    }
    int ans=0;
    for (int i=0; i<=n; i++){
        ans=max(ans, dp[i][0]);
    }
    cout<<ans<<endl;



    return 0;
}