#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7;
vector <int> v[maxn];
int h[maxn];
double eht[maxn];
bool mark[maxn];
double ans;

void dfs(int k){
    mark[k] = true;
//    cout << k << ": h :" << h[k] << " eht : " << eht[k] << endl;
    int deg = 0;
    for (int i = 0; i < v[k].size(); i++){
        if (mark[v[k][i]] == false){
            deg++;
            int x = v[k][i];
            h[x] = h[k] + 1;
            if (k != 1)
                eht[x] = eht[k] * (1.0 / (v[k].size() - 1));
            else
                eht[x] = eht[k] * (1.0 / v[k].size());
            dfs(x);
        }
    }
    if (deg == 0) {
        ans += h[k] * eht[k];
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    int n, beg, des;
    cin >> n;
    eht[1] = 1;
    for (int i = 1; i < n; i++){
        cin >> beg >> des;
        v[beg].push_back(des);
        v[des].push_back(beg);
    }
    dfs(1);
    cout << fixed << setprecision(6) << ans;
}