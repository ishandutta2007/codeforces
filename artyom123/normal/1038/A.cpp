#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> a(k);
    for (int i = 0; i < s.size(); i++) {
        a[s[i] - 'A']++;
    }
    int min_el = INF;
    for (int i = 0; i < k; i++) {
        min_el = min(min_el, a[i]);
    }
    cout << min_el * k;
    return 0;
}