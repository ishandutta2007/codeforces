#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, k, A, B;
vector < int > T;


int dfs(int l, int r){
    auto it = lower_bound(T.begin(), T.end(), l);
    auto it1 = upper_bound(T.begin(), T.end(), r);
    int sz = it1 - it;
    int answ = sz * (r - l + 1) * B;
    if (sz == 0) return A;
    if (l == r) return answ;
    int m = (r + l) / 2;
    return min(answ, dfs(l, m) + dfs(m + 1, r));
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> n >> k >> A >> B;
    for (int i = 1; i <= k; ++i){
        cin >> x;
        T.push_back(x);
    }
    n = (1<<n);
    sort(T.begin(), T.end());
    cout << dfs(1, n) << '\n';
    return 0;
}