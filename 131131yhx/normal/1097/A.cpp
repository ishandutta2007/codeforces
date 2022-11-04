#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

char ch[1111][11];

int main() {
    int t = 0;
    for(int i = 0; i <= 5; i++) scanf("%s", ch[i]);
    for(int i = 1; i <= 5; i++) if(ch[i][0] == ch[0][0] || ch[i][1] == ch[0][1]) {puts("YES"); return 0;}
    puts("NO");
    return 0;

}