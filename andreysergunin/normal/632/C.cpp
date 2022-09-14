#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

int comp (const string &a, const string &b) {
    if (a + b < b + a)
        return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0 ; i < n; ++i)
        cin >> s[i];
    sort(s.begin(), s.end(), comp);
    for (int i = 0; i < n; ++i)
        cout << s[i];
    cout << endl;
    return 0;
}