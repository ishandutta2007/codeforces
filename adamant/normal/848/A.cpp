#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int tt = n;
    string ans;
    char x = 'a';
    for(int k = 1000; k > 1; k--)
    {
        int t = k * (k - 1) / 2;
        while(t <= n)
        {
            n -= t;
            ans += string(k, x);
            x++;
            assert(x <= 'z');
        }
    }
    if(tt == 0)
        ans = "a";
    assert(1 <= ans.size() && ans.size() <= 100000);
    cout << ans << endl;
    return 0;
}