#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MaxN = 1e5 + 15;

int n;

bool can(int x, int y, int xx, int yy)
{
    if(x < 1 || x > n || y < 1 || y > n)
        return false;

    if(x > xx || y > yy)
    {
        swap(x, xx);
        swap(y, yy);
    }
    cout << "? " << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
    fflush(stdout);

    string s;
    cin >> s;

    if(s == "YES")
        return true;

    return false;
}

int dist(int x, int y, int xx, int yy)
{
    return abs(x - xx) + abs(y - yy);
}

vector <char> ans1, ans2;

int main()
{
//    freopen("input.txt", "r", stdin);
//    ios_base :: sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n;

    int x = 1, y = 1;

    while(dist(x, y, n, n) >= n)
    {
        if(can(x, y + 1, n, n))
        {
            ++y;
            ans1.push_back('R');
        }else
        {
            ++x;
            ans1.push_back('D');
        }
    }

    int xx = n;
    int yy = n;

    while(xx != x || yy != y)
    {
        if(can(xx - 1, yy, 1, 1))
        {
            ans2.push_back('D');
            --xx;
        }else
        {
            ans2.push_back('R');
            --yy;
        }
    }

    reverse(ans2.begin(), ans2.end());

    cout << "! ";
    for(auto q : ans1)
        cout << q;
    for(auto q : ans2)
        cout << q;

    cout << '\n';

    fflush(stdout);

    return 0;
}