#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", min(min(a, b - 1), c - 2) * 3 + 3);
    return 0;
}