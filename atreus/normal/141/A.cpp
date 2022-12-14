#include <bits/stdc++.h>

using namespace std;

int cnt[50], mark[50];

int main(){
    ios_base::sync_with_stdio(false);
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++)
        cnt[a[i] - 'A'] ++;
    for (int i = 0; i < b.size(); i++)
        cnt[b[i] - 'A'] ++;
    for (int i = 0; i < c.size(); i++)
        mark[c[i] - 'A'] ++;
    for (int i = 0; i < 40; i++)
        if (mark[i] != cnt[i])
            return cout << "NO" << endl, 0;
    cout << "YES" << endl;
}