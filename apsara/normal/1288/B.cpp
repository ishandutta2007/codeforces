#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;
int _, A, B;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &A, &B);
        int bn = 0;
        LL cur_b = 9;
        while (cur_b <= B) {
            bn++;
            cur_b = cur_b * 10 + 9;
        }
        printf("%I64d\n", (LL)A * bn);
    }
    return 0;
}

/*
3
1 11
4 2
191 31415926
*/