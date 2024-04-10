#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector < int > a;
    vector < int > a1;
    vector < int > b;
    vector < int > b1;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (i != 1) a1.push_back(x - a.back());
        a.push_back(x);
    }
    for (int i = 1; i <= n; ++i){
        cin >> x;
        if (i != 1) b1.push_back(x - b.back());
        b.push_back(x);
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    if (a[0] == b[0] && a1 == b1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}