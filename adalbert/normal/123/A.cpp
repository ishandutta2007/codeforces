#include <bits/stdc++.h>

using namespace std;

#define fir first
#define sec second
#define pb push_back

bool ok[2000];
int cnt[2000], res[2000];

bool simple(int u) {
    for (int i = 2; i * i <= u; i++)
        if (u % i == 0)
        return 0;
    return 1;
}

int main()
{
    string s;
    cin >> s;
    if (s.size() == 1) {
        cout << "YES\n";
        cout << s;
        return 0;
    }

    int sum = 0;

    for (int i = 1; i <= s.size(); i++)
        if (simple(i) && i * 2 > s.size())
        ok[i - 1] = 1, sum++;
    ok[0] = 1;
    sum++;

    for (auto i:s)
        cnt[i]++;

    for (int l = 0; l < 1000; l++)
        if (cnt[l] >= s.size() - sum) {
            cout << "YES\n";

            for (int i = 0; i < s.size(); i++)
                if (!ok[i])
                res[i] = l, cnt[l]--;

            int last = 0;
            for (int i = 0; i < s.size(); i++)
            if (ok[i]) {
                while (cnt[last] == 0)
                    last++;
                cnt[last]--;
                res[i] = last;
            }

            string ans = "";
            for (int i = 0; i < s.size(); i++)
                ans += res[i];
            cout << ans;
            return 0;
        }

    cout << "NO";
}