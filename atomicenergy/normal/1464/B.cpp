
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

    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
        for (int i = 0; i < s.size(); i++) if(s[i] != '?') s[i] = ('1' ^ '0' ^ s[i]);
    }
    ll seenzeros = 0;
    ll seenones = 0;
    ll start = 0;
    ll onesafter = 0;
    ll onesbefore = 0;
    ll zerosafter = 0;
    ll zerosbefore = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            seenzeros++;
            start += seenones * y;
            zerosafter++;
        }
        else {
            seenones++;
            start += seenzeros * x;
            onesafter++;
        }
    }
    ll mn = start;
    ll cur = start;
    for (int i = 0; i < s.size(); i++) {
        //cout << cur << endl;
        if (s[i] == '?') {
            onesafter--;
            cur -= y * zerosafter;
            cur -= x * zerosbefore;
            cur += x * onesafter;
            cur += y * onesbefore;
            mn = min(cur, mn);
            zerosbefore++;
        }
        if (s[i] == '0') {
            zerosafter--;
            zerosbefore++;
        }
        if (s[i] == '1') {
            onesafter--;
            onesbefore++;
        }
        //cout << cur << endl;
    }
    cout << mn << endl;


}