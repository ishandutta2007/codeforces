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
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

int _, x;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &x);
        bool ok = false;
        for (int i = 0; i <= 111; ++i) {
            if (x >= i * 11 && (x - i * 11) % 111 == 0) ok = true;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
3
33
144
69
*/