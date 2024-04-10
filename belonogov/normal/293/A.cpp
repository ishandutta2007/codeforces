#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 2e6 + 10;
const int inf = 1e9;

char s1[maxn];
char s2[maxn];
int a[2][2], ans[2];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n;
    scanf("%d", &n);
    n *= 2;
    scanf("%s", s1);
    scanf("%s", s2);
    for(int i = 0; i < n; i++)
    s1[i] = s1[i] - '0';
    for(int i = 0; i < n; i++)
    s2[i] = s2[i] - '0';

    for(int i = 0; i < n; i++)
    a[(int)s1[i]][(int)s2[i]]++;
    
    for(int i = 0; i < n; i++){
    int t = i % 2;
    if (a[1][1] > 0){
        ans[t]++;
        a[1][1]--;
        continue;
    }
    if (t == 0){
        if (a[1][0] > 0){
        a[1][0]--;
        ans[0]++;
        continue;
        }
        if (a[0][1] > 0)
        a[0][1]--;
    }
    if (t == 1){
        if (a[0][1] > 0){
        a[0][1]--;
        ans[1]++;
        continue;
        }
        if (a[1][0] > 0)
        a[1][0]--;
    }
    
    }
    if (ans[0] > ans[1])
    printf("First\n");
    if (ans[0] == ans[1])
    printf("Draw\n");
    if (ans[0] < ans[1])
    printf("Second\n");
    
    return 0;
}