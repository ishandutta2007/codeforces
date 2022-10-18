#include <bits/stdc++.h>

using namespace std;

int used[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        used[x]++;
    }
    int ans = 0, mid = 0, tec = 0;
    int i = 1, j = 2;
    while (i <= 200000){
        if (used[i] >= 2 && i != 1 && i <= j) tec -= used[i];
        if (used[i] == 0){
            ++i;
            continue;
        }
        j = max(j, i + 1);
        while (used[j] >= 2) tec += used[j], ++j;
        int cnt = tec + used[i] + used[j];
        if (cnt > ans) ans = cnt, mid = i;
        ++i;
    }
    deque < int > out;
    int delta = 1;
    for (int j = 1; j <= used[mid]; ++j) out.push_back(mid);
    while (used[mid + delta] >= 2){
        for (int j = 1; j <= used[mid + delta] - 1; ++j) out.push_back(mid + delta);
        out.push_front(mid + delta);
        delta++;
    }
    for (int j = 1; j <= used[mid + delta]; ++j) out.push_back(mid + delta);
    cout << out.size() << '\n';
    for (auto key : out) cout << key << " ";
    return 0;
}