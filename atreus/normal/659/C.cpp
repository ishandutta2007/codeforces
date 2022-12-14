#include <bits/stdc++.h>

using namespace std;

map <int, bool> mp;
vector <int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        mp[a] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        if (mp[i] == false){
            m -= i;
            if (m >= 0){
                cnt ++;
                v.push_back(i);
            }
            else
                break;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}