#include <bits/stdc++.h>

using namespace std;

int a[100005];
int cnt[100005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cnt[a[i]]++;
    multiset < int > Q;
    for (int i = 0; i <= 100000; ++i) if (cnt[i] != 0) Q.insert(cnt[i]);
    for (int i = n; i >= 1; --i){
        if ((int)Q.size() == 1){
            cout << i << '\n';
            return 0;
        }
        auto p = (*Q.begin()), p1 = (*Q.rbegin());
        if (p1 - p == 1){
            Q.erase(Q.find(p1));
            if ((*Q.rbegin()) == p){
                cout << i << '\n';
                return 0;
            }
            Q.insert(p1);
        }
        if (p == 1){
            Q.erase(Q.find(1));
            if ((*Q.begin()) == p1){
                cout << i << '\n';
                return 0;
            }
            Q.insert(1);
        }
        Q.erase(Q.find(cnt[a[i]]));
        cnt[a[i]]--;
        if (cnt[a[i]] != 0) Q.insert(cnt[a[i]]);
    }
    cout << 1 << '\n';
    return 0;
}