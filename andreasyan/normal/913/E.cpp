#include <bits/stdc++.h>
using namespace std;
bool ham(const string& a, const string& b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;
    return a < b;
}

string d[(1 << 8)][3];
string ans[(1 << 8)];

void pre()
{
    for (int x = 0; x < (1 << 8); ++x)
    {
        for (int z = 0; z < 3; ++z)
            d[x][z] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    }
    d[((1 << 1) | (1 << 3) | (1 << 5) | (1 << 7))][2] = "z";
    d[((1 << 2) | (1 << 3) | (1 << 6) | (1 << 7))][2] = "y";
    d[((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))][2] = "x";
    for (int iii = 0; iii < 100; ++iii)
    {
        for (int x = 0; x < (1 << 8); ++x)
        {
            if (ham("(" + d[x][0] + ")", d[x][2]))
                d[x][2] = "(" + d[x][0] + ")";
        }
        for (int x = 0; x < (1 << 8); ++x)
        {
            int z = 0;
            for (int i = 0; i < 8; ++i)
            {
                if (!(x & (1 << i)))
                    z |= (1 << i);
            }
            if (ham("!" + d[x][2], d[z][2]))
                d[z][2] = "!" + d[x][2];
        }
        for (int x = 0; x < (1 << 8); ++x)
        {
            if (ham(d[x][2], d[x][1]))
                d[x][1] = d[x][2];
        }
        for (int x = 0; x < (1 << 8); ++x)
        {
            for (int y = 0; y < (1 << 8); ++y)
            {
                if (ham(d[x][1] + "&" + d[y][2], d[(x & y)][1]))
                    d[(x & y)][1] = d[x][1] + "&" + d[y][2];
            }
        }
        for (int x = 0; x < (1 << 8); ++x)
        {
            if (ham(d[x][1], d[x][0]))
                d[x][0] = d[x][1];
        }
        for (int x = 0; x < (1 << 8); ++x)
        {
            for (int y = 0; y < (1 << 8); ++y)
            {
                if (ham(d[x][0] + "|" + d[y][1], d[(x | y)][0]))
                    d[(x | y)][0] = d[x][0] + "|" + d[y][1];
            }
        }
    }
    for (int x = 0; x < (1 << 8); ++x)
    {
        ans[x] = d[x][0];
        for (int z = 1; z < 3; ++z)
        {
            if (ham(d[x][z], ans[x]))
                ans[x] = d[x][z];
        }
    }
}

char s[10];
int main()
{
    pre();
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        scanf(" %s", s);
        int x = 0;
        for (int i = 0; i < 8; ++i)
        {
            if (s[i] == '1')
                x = (x | (1 << i));
        }
        cout << ans[x] << endl;
    }
    return 0;
}