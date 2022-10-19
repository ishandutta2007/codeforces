
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<int> v;
    for (char c : s) {
        v.push_back(c - 'a');
    }
    reverse(v.begin(), v.end());
    if (n == 1) {
        if (t == (1ll << v[0])) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if (n == 2) {
        if (t == (1ll << v[0]) - (1ll << v[1])) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }

    ll cur = (1ll << v[0]) - (1ll << v[1]);
    map<int, int> m;
    for (int i = 2; i < v.size(); i++) m[v[i]]++;
    int mnextra = 0;
    int mxextra = 0;
    t -= cur;
    for (int i = 0; i < 28; i++) {
        bool bit = t & 1;
        //cout << t << " " << m[i] << " " << i << " " << mnextra << " " << mxextra << endl;
        if (bit) {
            if ((m[i] + mnextra) % 2 == 0) mnextra++;
            if ((m[i] + mxextra) % 2 == 0) mxextra--;
        }
        else {
            if ((m[i] + mnextra) % 2 != 0) mnextra++;
            if ((m[i] + mxextra) % 2 != 0) mxextra--;
        }
        if (mnextra > mxextra) {
            cout << "No" << endl;
            return 0;
        }
        if (bit) {
            bit = false;
            t -= 1;
            mnextra--;
            mxextra--;
        }
        mnextra += -m[i];
        mxextra += m[i];
        mnextra /= 2;
        mxextra /= 2;
        t /= 2;
    }
    if (t >= mnextra && t <= mxextra) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}