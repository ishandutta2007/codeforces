#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
int c[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    multiset < int > Q;
    for (int i = 1; i <= n; ++i) Q.insert(b[i]);
    for (int i = 1; i <= n; ++i){
        int t = a[i];
        int mini = (*Q.begin());
        int x = n - t;
        auto it = Q.lower_bound(x);
        if (it == Q.end()){
            c[i] = (a[i] + mini) % n;
            Q.erase(Q.find(mini));
        }
        else{
            x = (*it);
            c[i] = (a[i] + x) % n;
            Q.erase(Q.find(x));
        }
    }
    for (int i = 1; i <= n; ++i) cout << c[i] << " ";
    return 0;
}