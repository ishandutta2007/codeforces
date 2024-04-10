#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <deque>

using namespace std;

const int MAXN = 1e6 + 10;

int main() {
    int n;
    char s[MAXN];
    scanf("%s", s);
    n = (int)strlen(s);
    deque<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'l')
            ans.push_back(i);
        else
            ans.push_front(i);
    }
    while (!ans.empty()) {
        printf("%d\n", ans.front() + 1);
        ans.pop_front();
    }
    return 0;
}