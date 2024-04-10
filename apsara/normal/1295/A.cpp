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
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        if (n % 2 == 1) printf("7"), n -= 3;
        while (n > 0) {
            printf("1");
            n -= 2;
        }
        puts("");
    }
    return 0;
}

/*

*/