#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

int n, A[1010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for(int i = n; i >= 1; i--) A[i] -= A[i - 1];
    vector <int> Ans;
    Ans.clear();
    for(int i = 1; i <= n; i++) {
        int flag = 1;
        for(int j = 1; i + j <= n; j++)
            if(A[j] != A[i + j]) flag = 0;
        if(flag) Ans.push_back(i);
    }
    printf("%d\n", Ans.size());
    for(int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
    putchar('\n');
    return 0;
}