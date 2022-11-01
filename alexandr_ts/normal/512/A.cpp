#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string s[200];

int a[600][600];

bool mm[600][600];

void ext()
{
    cout << "Impossible";
    exit(0);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    int ms = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ms = max(ms, (int)s[i].size());
    }
    for (int i = 0; i < ms; i++)
        for (int j = 1; j < n; j++)
            if (!mm[j][j - 1])
                if (s[j].size() >= i + 1 && s[j - 1].size() >= i + 1)
                if (s[j][i] != s[j - 1][i])
                    if (a[s[j][i]][s[j - 1][i]] == 2)
                        ext();
                    else
                        a[s[j][i]][s[j - 1][i]] = 1, a[s[j - 1][i]][s[j][i]] = 2, mm[j][j - 1] = mm[j - 1][j] = true;
//                else if (s[j][i] < s[j - 1][i])
//                    if (a[s[j][i]][s[j - 1][i]] == 1)
//                        ext();
//                    else
//                        a[s[j][i]][s[j - 1][i]] = 2, a[s[j - 1][i]][s[j][i]] = 1, mm[j][j - 1] = mm[j - 1][j] = true;
    string al;
    for (char ch = 'a'; ch <= 'z'; ch++)
        al += ch;
    for (int i = 1; i < n; i++)
        if (!mm[i - 1][i] && s[i].size() <= s[i - 1].size())
            ext();
    set <int> st;
    vector <char> ans;
    //cout << a['g']['n'] << " " << a['n']['g'] << " " << a['a']['s'] << endl;
    for (int i = 0; i < al.size(); i++)
    {
        for (int j = 0; j < al.size(); j++)
        {
            bool fnd = false;
            for (int k = 0; k < al.size(); k++)
                if (a[j + 'a'][k + 'a'] == 1)
                {
                    fnd = true;
                    break;
                }
            if (!fnd && !st.count(j))
            {
                ans.push_back((char)(j + 'a'));
                //cout << (char)(j + 'a');
                st.insert(j);
                for (int k = 0; k < al.size(); k++)
                    a[j + 'a'][k + 'a'] = a[k + 'a'][j + 'a'] = 0;

            }
        }
    }
    if (ans.size() < al.size())
        ext();
    else
        for (int i = 0; i < (int)ans.size(); i++)
            cout << ans[i];
}