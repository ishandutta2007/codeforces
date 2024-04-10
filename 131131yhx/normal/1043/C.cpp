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

int n;

char ch[1111];

int main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    int rv = 0;
    for(int i = 1; i < n; i++)
        if(!rv) {
            if(ch[i + 1] == 'a') {
                rv = 1;
                printf("1 ");
            } else printf("0 ");
        } else {
            if(ch[i + 1] == 'a') printf("0 ");
            else {
                rv = 0;
                printf("1 ");
            }
        }
    printf("%d\n", rv);
    return 0;
}