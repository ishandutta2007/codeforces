#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>

using namespace std;

int a, b;

vector <int> A(0), B(0);

int main() {
    scanf("%d%d", &a, &b);
    A.push_back(0);
    for(int i = 0; i < a; i++) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    //a++;
    int s = 0;
    for(int i = 0; i < b; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) {
            if(b == 1000000000) {
                s++;
                continue;
            }
            int tmp = lower_bound(A.begin(), A.end(), b + 1) - A.begin() - 1;
            B.push_back(tmp);
        }
    }
    sort(B.begin(), B.end());
    int ans = B.size();
    for(int i = 0; i < B.size(); i++)
        ans = min(ans, (int) B.size() - i - 1 + B[i]);
    printf("%d\n", ans + s);
    return 0;
}