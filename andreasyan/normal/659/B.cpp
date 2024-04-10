#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    string name;
    int x;
    ban(){}
    ban(string name, int x)
    {
        this->name = name;
        this->x = x;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.x > b.x;
}
 
int n, m;
vector<ban> a[N];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int x, u;
        cin >> name >> u >> x;
        a[u].push_back(ban(name, x));
    }
    for (int i = 1; i <= m; ++i)
    {
        sort(a[i].begin(), a[i].end());
        if (a[i].size() == 2)
        {
            cout << a[i][0].name << ' ' << a[i][1].name << endl;
            continue;
        }
        if (a[i][2].x == a[i][1].x)
        {
            cout << "?" << endl;
        }
        else
        {
            cout << a[i][0].name << ' ' << a[i][1].name << endl;
        }
    }
    return 0;
}