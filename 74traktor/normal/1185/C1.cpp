#include <bits/stdc++.h>

using namespace std;

int t[200005];
int p1[200005];
int p2[200005];

unordered_map < int, int > add;
int n, m;

void modify(int i, int x){
    while (i <= n){
        p1[i] += x;
        i = (i|(i + 1));
    }
}

void upd(int i, int x){
    while (i <= n){
        p2[i] += x;
        i = (i|(i + 1));
    }
}

int ans(int i){
    int sum = 0;
    while (i >= 1){
        sum += p1[i];
        i = (i&(i + 1)) - 1;
    }
    return sum;
}

int cnt(int i){
    int sum = 0;
    while (i >= 1){
        sum += p2[i];
        i = (i&(i + 1)) - 1;
    }
    return sum;
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    vector < int > b;
    for (int i = 1; i <= n; ++i) b.push_back(t[i]);
    sort(b.begin(), b.end());
    for (int i = 1; i <= n; ++i){
        int l = 0, r = n + 1;
        while (r - l > 1){
            int mid = (r + l) / 2;
            int sum = ans(mid);
            if (sum <= m - t[i]) l = mid;
            else r = mid;
        }
        cout << (i - 1) - cnt(l) << " ";
        int it = lower_bound(b.begin(), b.end(), t[i]) - b.begin() + 1 + add[t[i]];
        add[t[i]]++;
        modify(it, t[i]);
        upd(it, 1);
    }
    return 0;
}