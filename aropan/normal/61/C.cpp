#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 111;
const int MAXR = 7;

string C[MAXR] = {"I", "V", "X", "L", "C", "D", "M"};
int X[MAXR] = {1, 5, 10, 50, 100, 500, 1000};

int a;
string b, c;
long long x;
int ans[MAXN];
vector < pair < int, string> > R;

int ctoi(char c)
{
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    return -1;
}

char itoc(int x)
{
    if (0 <= x && x <= 9) return x + '0';
    if (10 <= x && x <= 35) return x + 'A' - 10;
    return -1;
}

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    cin >> a >> b;
    getline(cin, c);
    getline(cin, c);

    x = 0;
    for (int i = 0; i < (int)c.size(); i++)
       x = x * a + ctoi(c[i]);

    if (b != "R")
    {
        istringstream B(b);
        int base, n = 0;
        B >> base;

        do
        {
            ans[n++] = x % base;
            x /= base;
        } while (x);

        for (int i = n; i--; )
            printf("%c", itoc(ans[i]));
        printf("\n");
        return 0;
    }

    R.clear();
    for (int i = 0; i < MAXR; i++)
        R.push_back(make_pair(X[i], C[i]));

    for (int i = 0; i < MAXR; i += 2)
        for (int j = i + 1; j < i + 3 && j < MAXR; j++)
            R.push_back(make_pair(X[j] - X[i], C[i] + C[j]));

    sort(R.rbegin(), R.rend());

    for (int i = 0; i < (int)R.size(); i++)
    {
        for (int j = 0; j < x / R[i].first; j++)
            cout << R[i].second;
        x %= R[i].first;
    }
    cout << endl;

    return 0;
}