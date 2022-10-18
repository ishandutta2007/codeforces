#include <bits/stdc++.h>

using namespace std;

int a[200005];
int ss[200005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    map < int, pair < int, int > > g;
    int k = 0, pocl = -1;
    for (int i = 0; i < n; ++i){
        if (g.find(a[i] - 1) == g.end()){
            if (1 > k) pocl = i;
            k = max(k, 1);
            g[a[i]] = {i, 1};
            ss[i] = -1;
        }
        else{
            if (g[a[i] - 1].second + 1 > k)
                pocl = i;
            ss[i] = g[a[i] - 1].first;
            k = max(k, g[a[i] - 1].second + 1);
            g[a[i]] = {i, g[a[i] - 1].second + 1};
        }
    }
    cout << k << endl;
    vector < int > out;
    for (int i = 0; i < k; ++i){
        out.push_back(pocl + 1);
        pocl = ss[pocl];
    }
    for (int i = k - 1; i >= 0; --i) cout << out[i] << " ";
    return 0;
}