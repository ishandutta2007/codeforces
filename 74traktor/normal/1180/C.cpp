#include <bits/stdc++.h>

using namespace std;

#define int long long
deque < int > a;
int answ[300005][2];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, imax = 0, x;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        a.push_back(x);
        imax = max(imax, x);
    }
    int it = 1;
    while (a[0] != imax){
        answ[it][0] = a[0], answ[it][1] = a[1];
        int x1 = a[0], x2 = a[1];
        if (a[0] > a[1]){
            a.pop_front();
            a.pop_front();
            a.push_front(x1);
            a.push_back(x2);
        }
        else{
            a.pop_front();
            a.pop_front();
            a.push_back(x1);
            a.push_front(x2);
        }
        it++;
    }
    for (int i = 1; i <= q; ++i){
        cin >> x;
        if (x < it) cout << answ[x][0] << " " << answ[x][1] << '\n';
        else{
            x -= (it - 1);
            x %= (n - 1);
            if (x == 0) x = n - 1;
            cout << a[0] << " " << a[x] << '\n';
        }
    }
    return 0;
}