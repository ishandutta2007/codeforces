#include <bits/stdc++.h>

using namespace std;

#define int long long

int st[100];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    st[1] = 1;
    for (int i = 2; i <= 40; ++i) st[i] = st[i - 1] * 2;
    int n, k;
    cin >> n >> k;
    if (k > n){
        cout << "NO" << endl;
        return 0;
    }
    multiset < int > answ;
    for (int i = 40; i >= 1; --i){
        if (n >= st[i]){
            answ.insert(st[i]);
            n -= st[i];
        }
    }
    if ((int)answ.size() > k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    while ((int)answ.size() < k){
        auto p = (*answ.rbegin());
        answ.erase(answ.find(p));
        answ.insert(p / 2);
        answ.insert(p / 2);
    }
    for (auto key : answ) cout << key << " ";
    return 0;
}