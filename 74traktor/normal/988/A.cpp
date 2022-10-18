#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set < int > use;
    set < pair < int, int > > a;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (use.find(x) == use.end())
        a.insert({x, i});
        use.insert(x);
    }
    if (use.size() < k)
        cout << "NO" << endl;
    else{
            cout << "YES" << endl;
        int i = 0;
        for (auto key : a){
            cout << key.second + 1 << " ";
            ++i;
            if (i == k) break;
        }
    }
    return 0;
}