#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <fstream>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define first fs
#define second sc

using namespace std;

int main()
{
    // ifstream cin("infinite.in");
    // ofstream cout("infinite.out");

    int n;
    scanf("%d", &n);

    int h, t;
    scanf("%d:%d", &h, &t);

    int ans = 0;

    if (n == 24) {
        if (h > 23)
            h = h % 10;
    }
    else {
        if (h > 12)
            h = h % 10;
        if (h == 0)
            h = 10;
    }

    if (t >= 60)
        t = t % 10;

    if (h < 10)
        cout << 0;

    cout << h;

    cout << ":";

    if (t < 10)
        cout << 0;

    cout << t << endl;



}