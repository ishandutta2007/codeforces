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
    int n;
    cin >> n;
    int k = 0;
    int s = 0;
    for (; ;) {
        k += 5;
        int l = k;
        while (l % 5 == 0) {
            s += 1;
            l /= 5;
        }
        if (s > n) {
            cout << 0;
            return 0;
        }
        if (s == n) {
            cout << 5 << endl;
            for (int i = 0; i < 5; i++)
                cout << k + i << " ";
            return 0;
        }
    }
    return 0;
}