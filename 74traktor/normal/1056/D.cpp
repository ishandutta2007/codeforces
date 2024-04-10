#include <bits/stdc++.h>

using namespace std;

int n;
int temp[100005];
vector < int > G[100005];


void build(int v){
    int ans = 0;
    for (auto u : G[v]){
        build(u);
        ans += temp[u];
    }
    if (G[v].size() == 0)
        temp[v]++;
    else
        temp[v] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i){
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    build(1);
    sort(temp + 1, temp + n + 1);
    for (int i = 1; i <= n; ++i)
        cout << temp[i] << " ";
    return 0;
}