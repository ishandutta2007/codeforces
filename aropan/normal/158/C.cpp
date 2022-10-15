#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    string path = "/";
    path.reserve(32768);
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string com;
        cin >> com;
        if (com == "cd")
        {
            string s;
            cin >> s;
            if (s[0] == '/')
                path = s;
            else
                path += s;

            for (int i = 0; i < (int)path.size(); i++)
                if (path[i] == '/')
                    path[i] = ' ';

            vector <string> a;
            istringstream S(path);
            while (S >> s)
            {
                if (s == "..")
                    a.pop_back();
                else
                    a.push_back(s);
            }

            path = "/";
            for (int i = 0; i < (int)a.size(); i++)
                (path += a[i]) += "/";
        }
        else
        if (com == "pwd")
        {
            cout << path << "\n";
        }
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}