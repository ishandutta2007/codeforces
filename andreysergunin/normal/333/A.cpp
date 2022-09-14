#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n % 3 == 0)
        n /= 3;
    cout << n / 3 + 1;
    return 0;
}