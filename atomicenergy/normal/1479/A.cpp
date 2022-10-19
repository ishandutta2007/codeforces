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

int ask(int i) {
    cout << "? " << (i + 1) << endl;
    int x;
    cin >> x;
    return x;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int l = 0;
    int lval = ask(0);
    int r = n - 1;
    int rval = ask(n - 1);
    int m = (n - 1) / 2;
    int mval = ask(m);
    if (mval > lval) {
        r = m;
        m = 0;
        mval = lval;
        l = -1;        
    }
    else if (mval > rval) {
        l = m;
        m = n - 1;
        mval = rval;
        r = n;
    }
    while (m - l > 1 || r - m > 1) {
        if (m - l > r - m) {
            int newm = (l + m) / 2;
            int newmval = ask(newm);
            if (newmval > mval) {
                l = newm;
            }
            else {
                r = m;
                m = newm;
                mval = newmval;
            }
        }
        else {
            int newm = (r + m) / 2;
            int newmval = ask(newm);
            if (newmval > mval) {
                r = newm;
            }
            else {
                l = m;
                m = newm;
                mval = newmval;
            }
        }
    }
    cout << "! " << (m + 1) << endl;

}