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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int m = 0;
    vector<int> ans;
    while (n > 0) {
        m++;
        if (n % 2 == 1)
            ans.push_back(m);
        n /= 2;
    }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    
    return 0;
}