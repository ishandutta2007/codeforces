#include <bits/stdc++.h>
using namespace std;
const int N = 10004;

int z;
string name[N];
map<string, int> b[N];
int p[N];

int main()
{
    int q;
    cin >> q;
    int x = 0;
    while (q--)
    {
        string ty;
        cin >> ty;
        if (ty[0] == 'c')
        {
            string a;
            cin >> a;
            int n = a.size();
            string s;

            if (a[0] != '/')
            {
                for (int i = 0; i < n; ++i)
                {
                    if (a[i] == '/')
                    {
                        if (s == "..")
                        {
                            x = p[x];
                            s = "";
                            continue;
                        }
                        if (b[x].find(s) == b[x].end())
                        {
                            ++z;
                            name[z] = s;
                            b[x][s] = z;
                            p[z] = x;
                            x = z;
                        }
                        else
                        {
                            x = b[x][s];
                        }
                        s = "";
                    }
                    else
                    {
                        s += a[i];
                    }
                }
            }
            else
            {
                x = 0;
                for (int i = 1; i < n; ++i)
                {
                    if (a[i] == '/')
                    {
                        if (s == "..")
                        {
                            x = p[x];
                            s = "";
                            continue;
                        }
                        if (b[x].find(s) == b[x].end())
                        {
                            ++z;
                            name[z] = s;
                            b[x][s] = z;
                            p[z] = x;
                            x = z;
                        }
                        else
                        {
                            x = b[x][s];
                        }
                        s = "";
                    }
                    else
                    {
                        s += a[i];
                    }
                }
            }
            if (s == "..")
            {
                x = p[x];
                s = "";
                continue;
            }
            if (b[x].find(s) == b[x].end())
            {
                ++z;
                name[z] = s;
                b[x][s] = z;
                p[z] = x;
                x = z;
            }
            else
            {
                x = b[x][s];
            }
            s = "";
        }
        else
        {
            vector<int> v;
            for (int y = x; y != 0; y = p[y])
                v.push_back(y);
            reverse(v.begin(), v.end());
            cout << "/";
            for (int i = 0; i < v.size(); ++i)
                cout << name[v[i]] << "/";
            cout << endl;
        }
    }
    return 0;
}