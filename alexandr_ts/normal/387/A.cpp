#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int a[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int n;
    //cin >> n;
    //for(int i = 0; i < n; i++)
    //cin >> a[i];
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int a1 = 10 * (s1[0] - '0') + s1[1] - '0';
    int a2 = 10 * (s1[3] - '0') + s1[4] - '0';
    int b1 = 10 * (s2[0] - '0') + s2[1] - '0';
    int b2 = 10 * (s2[3] - '0') + s2[4] - '0';
    int c1;
    int c2;
    c2 = a2 - b2;
    if(c2 < 0)
    {
        c2 += 60;
        a1--;
    }
    c1 = a1 - b1;
    c1 = (c1 + 24) % 24;
    if(c1 / 10 <= 0)
        cout << 0;
    cout << c1 << ":";
    if(c2 / 10 <= 0)
        cout << "0";
    cout << c2;
    return 0;
}