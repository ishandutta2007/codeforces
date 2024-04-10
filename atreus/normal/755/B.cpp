#include <bits/stdc++.h>

using namespace std;

int a[30];

int main (){
    ios_base::sync_with_stdio(false);
    int n, m, cnt = 0;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < m; i++){
        string a;
        cin >> a;
        for (int j = 0; j < n; j++){
            if (s[j] == a)
                cnt ++;
        }
    }
    int pb, eb;
    eb = cnt / 2;
    pb = cnt - eb;
    n -= cnt;
    m -= cnt;
    n += pb;
    m += eb;
    if (n > m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}