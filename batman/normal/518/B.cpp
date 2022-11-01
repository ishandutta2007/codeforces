#include <iostream>
using namespace std;
int cnt1[52], cnt2[52];
int get_val(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    return 26 + c - 'A';
}
int main()
{
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
        cnt1[get_val(s[i])]++;
    for (int i = 0; i < t.size(); i++)
        cnt2[get_val(t[i])]++;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < 52; i++)
    {
        int mn = min(cnt1[i], cnt2[i]);
        ans1 += mn;
        cnt1[i] -= mn;
        cnt2[i] -= mn;
    }
    for (int i = 0; i < 52; i++)
    {
        int mn = min(cnt1[i], cnt2[(i + 26) % 52]);
        ans2 += mn;
        cnt1[i] -= mn;
        cnt2[(i + 26) % 52] -= mn;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}