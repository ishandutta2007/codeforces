#include <bits/stdc++.h>

using namespace std;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector < int > a;
    bool f = true;
    for (int i = 0; i < n; ++i){
        if ((1<<(i + 1)) > x && f){
            f = false;
        }
        else a.push_back((1<<i));
    }
    if ((int)a.size() == 0){
        cout << 0 << '\n';
        return 0;
    }
    if ((int)a.size() == 1){
        if (a[0] != x){
            cout << 1 << '\n';
            cout << a[0] << '\n';
        }
        else{
            cout << 0 << '\n';
        }
        return 0;
    }
    vector < int > out;
    out.push_back(a[0]);
    out.push_back(a[1]);
    int lef = 2;
    while ((int)out.size() <= (1<<n)){
        int sz = out.size();
        for (int i = 0; i < sz - 1; ++i){
            out.push_back(out[i]);
        }
        if (lef == (int)a.size()) break;
        out.push_back(a[lef]);
        lef++;
    }
    cout << out.size() << '\n';
    for (auto key : out) cout << key << " ";
    return 0;
}