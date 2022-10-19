using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

int n;

int check(int a) {
    cout << "? " << ((a + n) % n) + 1 << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m;
    cin >> n >> m;
    vector<bool> cleared;
    //check 0-0
    check(0);
    int start = 0;
    int end = 0;
    for (int i = 1; i <= 500; i++) {
        end = start + min(i, (n - 1) / 2) - 1;
        int x = check(end + 1);
        if (x > m) break;
        start = end + 1;
        //check 0-0
        //chcek 1-2
        //check 3-6
        //check 7-10
    }
    //we know the answer is from start to end;
    int mn = start;
    int mx = end;
    while (mx != mn) {
        int md = (mn + mx) / 2;
        int x = check(md);
        if (x == m) {
            mn = md;
            mx = md;
            break;
        }
        if (x > m) {
            mx = md-1;
        }
        if (x < m) {
            mn = md+1;
        }
    }
    cout << "! " << (mn % n) + 1 << endl;

}