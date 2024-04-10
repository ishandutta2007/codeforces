#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    bool flag = true;
    if (n == 2){
        cout << 1 << '\n';
        return 0;
    }
    int add = a[2].first - a[1].first;
    for (int i = 3; i < n; ++i){
        if (a[i].first - a[i - 1].first != add) flag = false;
    }
    if (flag){
        cout << a[0].second << '\n';
        return 0;
    }
    flag = true;
    add = a[2].first - a[0].first;
    for (int i = 3; i < n; ++i){
        if (a[i].first - a[i - 1].first != add) flag = false;
    }
    if (flag){
        cout << a[1].second << '\n';
        return 0;
    }
    flag = true;
    add = a[1].first - a[0].first;
    for (int i = 2; i < n; ++i){
        if (a[i].first - a[i - 1].first != add){
            if (i == n - 1 && flag){
                cout << a[i].second << '\n';
                return 0;
            }
            if (i == n - 1 && !flag) break;
            if (a[i + 1].first - a[i - 1].first != add) flag = false;
            else{
                for (int j = i + 2; j < n; ++j){
                    if (a[j].first - a[j - 1].first != add) flag = false;
                }
                if (flag){
                    cout << a[i].second << '\n';
                }
                else cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}