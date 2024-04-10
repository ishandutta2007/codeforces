#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector < pair <int, char> > a;
map <char, int> m;
string s;
int x;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> s;
    cin >> x;

    for (int i = 0; i < (int)s.size(); i++)
        m[s[i]]++;

    for (map <char, int> :: iterator iter = m.begin(); iter != m.end(); iter++)
        a.push_back(make_pair(iter->second, iter->first));

    sort(a.rbegin(), a.rend());

    while ((int)a.size() && a[(int)a.size() - 1].first <= x)
    {
        x -= a[(int)a.size() - 1].first;
        a.pop_back();
    }

    m.clear();
    for (int i = 0; i < (int)a.size(); i++)
        m[a[i].second] = 1;


    printf("%d\n", (int)a.size());
    for (int i = 0; i < (int)s.size(); i++)
        if (m.find(s[i]) != m.end())
            printf("%c", s[i]);
    printf("\n");
    return 0;
}