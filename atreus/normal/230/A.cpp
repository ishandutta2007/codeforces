#include <bits/stdc++.h>

using namespace std;

pair <int, int> p[1100];

int main(){
    ios_base::sync_with_stdio(false);
    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort (p, p + n);
    for (int i = 0; i < n; i++){
        if (s > p[i].first)
            s += p[i].second;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}