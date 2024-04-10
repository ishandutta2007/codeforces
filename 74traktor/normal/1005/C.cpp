#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[120005];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < int > b;
    for (int i = 1; i <= (int)1e10; i *= 2)  b.push_back(i);
    set < int > use;
    map < int, int > Q;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        use.insert(a[i]);
        if (Q.find(a[i]) == Q.end()) Q[a[i]] = 1;
        else Q[a[i]]++;
    }
    int h = n;
    for (int i = 0; i < n; ++i){
        bool f = false;
        for (auto key : b){
            if (use.find(key - a[i]) != use.end()){
                if (key - a[i] == a[i]){
                    if (Q[a[i]] >= 2) f = true;
                }
                else f = true;
            }
        }
        if (f){
            //cout << i << endl;
            h--;
        }
    }
    cout << h << endl;
    return 0;
}