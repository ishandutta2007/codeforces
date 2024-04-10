#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define int long long
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

map<string, string> p, ty;
map<string, int> x, y, border, spacing, q;
map<string, vector<string> > a;

int getx(string name)
{
    if (ty[name] == "Widget")
        return x[name];
    else if (ty[name] == "HBox")
    {
        if (q[name] == 0)
            return 0;
        else
            return x[name] + (q[name] - 1) * spacing[name] + 2 * border[name];
    }
    else
    {
        if (q[name] == 0)
            return 0;
        else
            return x[name] + border[name] * 2;
    }
}

int gety(string name)
{
    if (ty[name] == "Widget")
        return y[name];
    else if (ty[name] == "HBox")
    {
        if (q[name] == 0)
            return 0;
        else
            return y[name] + border[name] * 2;
    }
    else
    {
        if (q[name] == 0)
            return 0;
        else
            return y[name] + (q[name] - 1) * spacing[name] + 2 * border[name];
    }
}

set<string> c;

void dfs(string name)
{
    if (c.find(name) != c.end())
        return;
    c.insert(name);
    for (int i = 0; i < a[name].size(); ++i)
    {
        string h = a[name][i];
        dfs(h);
        if (ty[name] == "HBox")
        {
            x[name] += getx(h);
            y[name] = max(y[name], gety(h));
        }
        else
        {
            y[name] += gety(h);
            x[name] = max(x[name], getx(h));
        }
    }
}

void solv()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "Widget")
        {
            string u;
            cin >> u;
            string name;
            int xx = 0, yy = 0;
            for (int i = 0; ; ++i)
            {
                if ('a' <= u[i] && u[i] <= 'z')
                    name += u[i];
                else if ('0' <= u[i] && u[i] <= '9')
                {
                    xx = (xx * 10 + u[i] - '0');
                }
                else if (u[i] == ',')
                    break;
            }
            int ast = 1;
            for (int i = u.size() - 1; ; --i)
            {
                if ('0' <= u[i] && u[i] <= '9')
                {
                    yy = yy + ast * (u[i] - '0');
                    ast *= 10;
                }
                else if (u[i] == ',')
                    break;
            }
            ty[name] = s;
            x[name] = xx;
            y[name] = yy;
        }
        else if (s == "VBox" || s == "HBox")
        {
            string name;
            cin >> name;
            ty[name] = s;
            x[name] = y[name] = 0;
        }
        else
        {
            string name;
            for (int i = 0; ; ++i)
            {
                if (s[i] == '.')
                    break;
                name += s[i];
            }
            string tyy;
            for (int i = 0; ; ++i)
            {
                if (s[i] == '.')
                {
                    for (i = i + 1; ; ++i)
                    {
                        if (s[i] == '(')
                            break;
                        tyy += s[i];
                    }
                    break;
                }
            }
            if (tyy == "pack")
            {
                string name1;
                for (int i = 0; ; ++i)
                {
                    if (s[i] == '(')
                    {
                        for (i = i + 1; ; ++i)
                        {
                            if (s[i] == ')')
                                break;
                            name1 += s[i];
                        }
                        break;
                    }
                }
                p[name1] = name;
                a[name].push_back(name1);
                q[name]++;
            }
            else
            {
                int xx = 0;
                for (int i = 0; ; ++i)
                {
                    if (s[i] == '(')
                    {
                        for (i = i + 1; ; ++i)
                        {
                            if (s[i] == ')')
                                break;
                            xx = (xx * 10 + s[i] - '0');
                        }
                        break;
                    }
                }
                if (tyy == "set_border")
                    border[name] = xx;
                else
                    spacing[name] = xx;
            }
        }
    }
    for (map<string, int>::iterator it = x.begin(); it != x.end(); ++it)
    {
        string name = it->first;
        dfs(name);
    }
    for (map<string, int>::iterator it = x.begin(); it != x.end(); ++it)
    {
        string name = it->first;
        cout << name << ' ' << getx(name) << ' ' << gety(name) << endl;
    }
}

int32_t main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}