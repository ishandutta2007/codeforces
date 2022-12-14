#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> g[256];

void gen(const vector<string>& v)
{
    /*cout << "--BEG--" << endl;
    for(auto i : v)
    {
        cout << i << endl;
    }
    cout << "--END--" << endl;*/
    if(v.size() <= 1)
        return;
    char last = '0';

    vector<string> was;
    vector<char> been;
    bool nonemp = false;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i].empty())
        {
            if(nonemp)
            {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
        else
            nonemp = true;
        if(v[i][0] != last)
        {
            for(char j : been)
            {
                g[v[i][0]].push_back(j);
            }
            been.push_back(v[i][0]);
            last = v[i][0];
            gen(was);
            was.clear();
        }
        if(not v[i].empty())
        {
            was.push_back(v[i].substr(1, string::npos));
        }
    }
    gen(was);
}

int tout[256];
int used[256];
int timer = 0;

void dfs(char c)
{
    if(used[c] == 1)
    {
        cout << "Impossible" << endl;
        exit(0);
    }
    used[c] = 1;
    for(char s : g[c])
    {
        if(used[s] != 2)
            dfs(s);
    }
    tout[c] = timer++;
    used[c] = 2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    gen(a);

    /*for(auto i : g)
    {
        cout << i.first << ": ";
        for(auto j : i.second)
        {
            cout << j << ", ";
        }
        cout << endl;
    }*/
    for(char i = 'a'; i <= 'z'; ++i)
    {
        if(used[i] == 0)
            dfs(i);
    }
    vector<pair<int, char>> v;
    for(char i = 'a'; i <= 'z'; ++i)
    {
        v.push_back({tout[i], i});
        //cout << i << " " << tout[i] << endl;
    }
    sort(v.begin(), v.end());
    for(auto i : v)
        cout << i.second;
    return 0;
}