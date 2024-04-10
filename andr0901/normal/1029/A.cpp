#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

bool check(string &lol) {
    int ans = 0;
    for (int i = 0; i < lol.size(); i++) {
        if (i + n > lol.size()) break;
        string temp2;
        for (int j = i; j < i + n; j++) {
            temp2 += lol[j];
        }
        if (temp2 == s) ans++;
       // cout << temp2 << ' ';
    }
    //cout << ans << " ";
    return (ans == 2);
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        string temp;
        for (int j = n - i - 1; j < n; j++) temp += s[j];
        string lol = s + temp;
        //cout << lol << "\n";
        if (check(lol)) {
            for (int l = 1; l < k; l++) s += temp;
            cout << s;
            return 0;
        }
    }
    return 0;
}