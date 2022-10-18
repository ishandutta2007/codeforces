#include <bits/stdc++.h>

using namespace std;

vector < int > g[100005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x, y;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int kol = 0;
    for (int i = 1; i <= n; ++i){
        if ((int)g[i].size() == 1) kol++;
    }
    cout << fixed << setprecision(7) << k / (double)(kol) * 2 << '\n';
    return 0;
}