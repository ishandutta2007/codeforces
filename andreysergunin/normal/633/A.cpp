#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i <= c; i += a) {
        if ((c - i) % b == 0) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}