#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

pair <int, int> operator+(const pair <int, int> &a, const pair <int, int> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

pair <int, int> operator-(const pair <int, int> &a, const pair <int, int> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

map <char, pair <int, int> > Map;

pair <int, int> d[105];

int main()
{
    Map['U'] = make_pair(0, 1);
    Map['D'] = make_pair(0, -1);
    Map['L'] = make_pair(-1, 0);
    Map['R'] = make_pair(1, 0);

    int a, b;
    cin >> a >> b;

    string str;
    cin >> str;

    for (int i = 1; i <= str.size(); ++ i)
        d[i] = d[i - 1] + Map[str[i - 1]];

    pair <int, int> all = d[str.size()];

    for (int i = 0; i < str.size(); ++ i) {
        pair <int, int> disp = make_pair(a, b) - d[i];

        bool every_x = false;
        int x;
        if (all.first == 0) {
            if (disp.first != 0)
                continue;
            every_x = true;
        }
        else {
            if (disp.first % all.first == 0)
                x = disp.first / all.first;
            else
                continue;
        }

        bool every_y = false;
        int y;
        if (all.second == 0) {
            if (disp.second != 0)
                continue;
            every_y = true;
        }
        else {
            if (disp.second % all.second == 0)
                y = disp.second / all.second;
            else
                continue;
        }

        if (every_x) {
            if (every_y) {
                cout << "Yes\n";
                return 0;
            }
            else if (y >= 0) {
                cout << "Yes\n";
                return 0;
            }
        }
        else {
            if (every_y) {
                if (x >= 0) {
                    cout << "Yes\n";
                    return 0;
                }
            }
            else if (x >= 0 && x == y) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}