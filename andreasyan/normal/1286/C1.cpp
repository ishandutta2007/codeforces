#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 102;

int n;
multiset<vector<int> > ss;

char ans[N];
void dfs(vector<int> q, int ii)
{
    for (int i = 0; i < 26; ++i)
    {
        q[i]++;
        if (ss.find(q) != ss.end())
        {
            ans[ii] = i + 'a';
            dfs(q, ii + 1);
        }
        q[i]--;
    }
}

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "? 1 1" << endl;
        string s;
        cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    cout << "? 1 " << n << endl;
    for (int i = 1; i <= (n * (n + 1)) / 2; ++i)
    {
        vector<int> q;
        q.assign(26, 0);
        string s;
        cin >> s;
        int m = s.size();
        for (int j = 0; j < m; ++j)
        {
            q[s[j] - 'a']++;
        }
        ss.insert(q);
    }
    cout << "? 2 " << n << endl;
    for (int i = 1; i <= ((n - 1) * n) / 2; ++i)
    {
        vector<int> q;
        q.assign(26, 0);
        string s;
        cin >> s;
        int m = s.size();
        for (int j = 0; j < m; ++j)
        {
            q[s[j] - 'a']++;
        }
        ss.erase(ss.find(q));
    }
    cout << "? 1 1" << endl;
    string s;
    cin >> s;
    vector<int> q;
    q.assign(26, 0);
    q[s[0] - 'a']++;
    ans[0] = s[0];
    dfs(q, 1);
    cout << "! " << ans << endl;
    return 0;
}