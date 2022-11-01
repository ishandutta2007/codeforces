#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int l = 0, ml = 0, sp = 0;
    for(int i = 0; i < n; ++i)
    {
        l += (s[i] == '[' ? 1 : -1);
        ml = max(ml, l);
        sp += (s[i] == ']' && s[i-1] == '[');
    }
    int h = 2*ml+1;
    vector<string> a(h, string(n+3*sp, ' '));
    l = 0;
    for(int i = 0, p = 0; i < n; ++i, ++p)
    {
        if (s[i] == ']' && s[i-1] == '[') p += 3;
        if (s[i] == '[') ++l;
        int c = 2*(ml-l)+1, t = (h-c)/2;
        //cout << l << ' ' << h << ' ' << t << ' ' << p << endl;
        a[t-1][p] = a[h-t][p] = '+';
        for(int j = t; j < h-t; ++j) a[j][p] = '|';
        int st = p + (s[i] == '[' ? 1 : -1);
        a[t-1][st] = a[h-t][st] = '-';
        if (s[i] == ']') --l;
    }
    for(auto& s : a) cout << s << '\n';
}