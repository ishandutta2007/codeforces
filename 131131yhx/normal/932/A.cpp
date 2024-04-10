#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

char ch[100010];

int main() {
    scanf("%s", ch);
    int n = strlen(ch);
    for(int i = 0; i < n; i++) putchar(ch[i]);
    for(int i = n - 1; i >= 0; i--) putchar(ch[i]);
    return 0;
}