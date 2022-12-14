#include <bits/stdc++.h>

using namespace std;

pair <int, int> p[120];
bool mark[120];
vector <int> v;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i].first >> p[i].second;
    sort (p, p + n);
    for (int i = 1; i <= 100; i++){
        bool cur = true;
        for (int j = 0; j < n; j++){
            int a = p[j].first;
            if (a % i == 0)
                a /= i;
            else
                a = (a / i) + 1;
            if (a != p[j].second)
                cur = false;
        }
        if (cur == true)
            mark[i] = true;
    }
    int cnt = 0, ans;
    for (int i = 1; i <= 100; i++){
        if (mark[i] == true){
            ans = i;
            cnt ++;
            v.push_back((n + ans - 1) / ans);
        }
    }
    for (int i = 0; i < v.size(); i++)
    if (v.size() == 0){
        cout << -1 << endl;
        return 0;
    }
    if (v.size() == 1){
        cout << v[0] << endl;
        return 0;
    }
    for (int i = 0; i < v.size() - 1; i++){
        if (v[i] != v[i + 1]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << v[0] << endl;
}