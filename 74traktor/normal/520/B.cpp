#include <bits/stdc++.h>

using namespace std;

int inf = 4 * 1e4;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    unordered_set < int > used;
    cin >> n >> m;
    vector < pair < int, int > > Q;
    Q.push_back({n, 0});
    int head = 0;
    used.insert(n);
    if (n == m){
        cout << 0 << '\n';
        return 0;
    }
    while (1){
        int x = Q[head].first;
        if (used.find(x - 1) == used.end() && x - 1 >= 0){
            Q.push_back({x - 1, Q[head].second + 1});
            used.insert(x - 1);
            if (x - 1 == m){
                cout << Q[head].second + 1 << endl;
                return 0;
            }
        }
        if (used.find(2 * x) == used.end() && 2 * x < inf){
            Q.push_back({2 * x, Q[head].second + 1});
            used.insert(2 * x);
            if (x * 2 == m){
                cout << Q[head].second + 1 << endl;
                return 0;
            }
        }
        head++;
    }
    return 0;
}