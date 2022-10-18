#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int logn = 65;

string tmpl(int k)
{
    string r;
    for(int i = 0; i < logn; i++)
    {
        r += char('0' + k % 2);
        k /= 10;
    }
    return r;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    map<string, int> me;
    while(t--)
    {
        char t;
        cin >> t;
        if(t == '+')
        {
            int k;
            cin >> k;
            me[tmpl(k)]++;
        }
        else if(t == '-')
        {
            int k;
            cin >> k;
            me[tmpl(k)]--;
        }
        else
        {
            string s;
            cin >> s;
            reverse(begin(s), end(s));
            while(s.size() < logn)
                s += '0';
            cout << me[s] << endl;
        }
    }
	return 0;
}