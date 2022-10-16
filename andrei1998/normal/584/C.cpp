#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    t = n - t;

    string s1, s2;
    cin >> s1 >> s2;

    vector <int> simples, doubles;
    for (int i = 0; i < n; ++ i)
        if (s1[i] != s2[i])
            simples.push_back(i);
        else
            doubles.push_back(i);

    string ans;
    for (int i = 0; i < n; ++ i)
        for (char ch = 'a'; ch <= 'z'; ++ ch)
            if (ch != s1[i] && ch != s2[i]) {
                ans += ch;
                break;
            }

    int t1 = t, t2 = t;
    while (t) {
        if (t1 >= 1 && t2 >= 1 && doubles.size()) {
            int pos = doubles.back(); doubles.pop_back();
            ans[pos] = s1[pos];
            t1--, t2--;
        }
        else if (t1 >= 1 && simples.size()) {
            int pos = simples.back(); simples.pop_back();
            ans[pos] = s1[pos];
            t1--;
        }
        else if (t2 >= 1 && simples.size()) {
            int pos = simples.back(); simples.pop_back();
            ans[pos] = s2[pos];
            t2--;
        }
        else
            break;
    }

    if (!t1 && !t2)
        cout << ans << '\n';
    else
        cout << "-1\n";
    return 0;
}