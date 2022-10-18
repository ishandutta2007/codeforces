#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<string, string> lol;
    for(int i = 0; i < q; i++)
    {
        string a, b;
        cin >> a >> b;
        lol[a] = b;
    }
    int ans = 0;
    for(int mask = 0; mask < round(pow(6, n)); mask++)
    {
        string cur;
        int t = mask;
        for(int i = 0; i < n; i++){
            cur += char('a' + t % 6);
            t /= 6;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(lol.count(cur.substr(0, 2)))
                cur = lol[cur.substr(0, 2)] + cur.substr(2);
            else
                goto out;
        }
        if(cur == "a")
            ans++;
        out:;
    }

    cout << ans << "\n";
}