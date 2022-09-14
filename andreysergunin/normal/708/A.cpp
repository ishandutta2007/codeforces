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
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>


#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;


int main() {
    string s;
    cin >> s;
    int n = sz(s);
    int state = 0;
    for (int i = 0; i < n; ++i) {
        if (state == 0) {
            if (s[i] != 'a') {
                --s[i];
                state = 1;
            }
        } else if (state == 1) {
            if (s[i] == 'a') {
                state = 2;
            } else {
                --s[i];
            }
        }
    }
    if (state == 0) {
        s[n - 1] = 'z';
    }
    cout << s << "\n";
}