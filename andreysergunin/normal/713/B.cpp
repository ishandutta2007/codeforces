#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <tuple>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

const int INF = 1e9;

vector<int> solve(int x1, int y1, int x2, int y2, int x) {
    int k;

    int l = y1 - 1, r = y2;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? ";
        cout << x1 << " " << y1 << " " << x2 << " " << m << endl;
        cout << flush;
        cin >> k;
        if (k == x)
            r = m;
        else 
            l = m;
    }

    int up = r;

    l = y1; r = y2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? ";
        cout << x1 << " " << m << " " << x2 << " " << y2 << endl;
        cout << flush;
        cin >> k;
        if (k == x)
            l = m;
        else 
            r = m;
    }

    int down = l;


    l = x1 - 1; r = x2;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? ";
        cout << x1 << " " << y1 << " " << m << " " << y2 << endl;
        cout << flush;
        cin >> k;
        if (k == x)
            r = m;
        else 
            l = m;
    }

    int right = r;



    l = x1; r = x2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cout << "? ";
        cout << m << " " << y1 << " " << x2 << " " << y2 << endl;
        cout << flush;
        cin >> k;
        if (k == x)
            l = m;
        else 
            r = m;
    }

    int left = l;

    // cout << left << " " << down << " " << right << " " << up << endl;

    return {left, down, right, up};
}

int main() {
    int n;
    cin >> n;
    int k;
    
    vector<int> a = solve(1, 1, n, n, 2);

    int left = a[0], down = a[1], right = a[2], up = a[3];

    vector<int> res1, res2;

    bool f = true;
    
    if (left != right) {
        cout << "? ";
        cout << left + 1 << " " << down << " " << right << " " << up << endl;
        cout << flush;
        cin >> k;
        if (k == 1) {
            f = false;
            res1 = solve(left + 1, down, right, up, 1);
        }
        if (f) {
            cout << "? ";
            cout << left << " " << down << " " << right - 1 << " " << up << endl;
            cout << flush;
            cin >> k;
            if (k == 1) {
                f = false;
                res1 = solve(left, down, right - 1, up, 1);
            }
        }
        if (f) {
            cout << "? ";
            cout << left << " " << down + 1 << " " << right << " " << up << endl;
            cout << flush;
            cin >> k;
            if (k == 1) {
                f = false;
                res1 = solve(left, down + 1, right, up, 1);
            }
        }
    }
    else {
        cout << "? ";
        cout << left << " " << down + 1 << " " << right << " " << up << endl;
        cout << flush;
        res1 = solve(left, down + 1, right, up, 1);

    }


    f = true;

    if (res1[0] == left && left != right && f) {
        cout << "? ";
        cout << left + 1 << " " << down << " " << right << " " << up << endl;
        cout << flush;
        cin >> k;
        if (k == 1) {
            f = false;
            res2 = solve(left + 1, down, right, up, 1);
        }
    }

    if (res1[1] == down && down != up && f) {
        cout << "? ";
        cout << left << " " << down + 1 << " " << right << " " << up << endl;
        cout << flush;
        cin >> k;
        if (k == 1) {
            f = false;
            res2 = solve(left, down + 1, right, up, 1);
        }
    }

    if (res1[2] == right && left != right && f) {
        cout << "? ";
        cout << left << " " << down << " " << right - 1 << " " << up << endl;
        cout << flush;
        cin >> k;
        if (k == 1) {
            f = false;
            res2 = solve(left, down, right - 1, up, 1);
        }
    }

    if (res1[3] == up && down != up && f) {
        cout << "? ";
        cout << left << " " << down << " " << right << " " << up - 1 << endl;
        cout << flush;
        cin >> k;
        if (k == 1) {
            f = false;
            res2 = solve(left, down, right, up - 1, 1);
        }
    }


    cout << "! ";
    for(int i = 0; i < 4; ++i)
        cout << res1[i] << " ";
    for(int i = 0; i < 4; ++i)
        cout << res2[i] << " ";
    cout << endl;
    cout << flush;
    return 0;
}