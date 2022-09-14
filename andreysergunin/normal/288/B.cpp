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

using namespace std;

const int P = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long ans = 1;
    for (int i = 0; i < k - 1; i++)
        ans = (ans * k) % P;
    for (int i = 0; i < n - k; i++)
        ans = (ans * (n - k)) % P;
    cout << ans;
    return 0;
}