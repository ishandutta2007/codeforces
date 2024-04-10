#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    multiset < int > a;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.insert(x);
    }
    int mini = 0;
    for (int i = 0; i < k; ++i){
        bool f = true;
        while (a.size() > 0 && (*a.begin()) <= mini)
            a.erase((*a.begin()));
        if (a.size() == 0)
            cout << 0 << '\n';
        else{
            cout << (*a.begin()) - mini << endl;
            mini += ((*a.begin()) - mini);
            a.erase((*a.begin()));
        }
    }
}