#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <bitset>

using namespace std;

char ch[111111];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", ch + 1);
    sort(ch + 1, ch + n + 1);
    puts(ch + 1);
    return 0;
}