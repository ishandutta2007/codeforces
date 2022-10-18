#include <bits/stdc++.h>

using namespace std;

map < int, vector < int > > Q;
map < int, int > R;
int ans[5005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        Q[x].push_back(i);
    }
    int last = 0;
    set < int > Q1;
    for (int i = 1; i <= k; ++i) Q1.insert(i);
    for (auto key : Q){
        if ((int)key.second.size() > k){
            cout << "NO" << '\n';
            return 0;
        }
        set < int > T;
        for (auto key1 : key.second){
            if ((int)Q1.size() != 0){
                ans[key1] = (*Q1.begin());
                Q1.erase(Q1.begin());
                T.insert(ans[key1]);
            }
            else{
                for (int pos = 1; pos <= k; ++pos){
                    if (T.find(pos) == T.end()){
                        ans[key1] = pos;
                        T.insert(pos);
                        break;
                    }
                }
            }
        }
    }
    if (Q1.size() != 0){
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    return 0;
}