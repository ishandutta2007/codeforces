#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)


const int maxn = 1e6 + 10;
int a[maxn];

void solve(int n){
    if (n <= 0) return ;
    int q;
    for(q = 1; q < n; q = q * 2 + 1);

    for(int i = q - n; i <= n; i++)
        a[i] = n - (i - (q - n));
    solve(q - n - 1);
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    solve(n);
    cout << n * 1ll * (n + 1) << endl;
    for(int i = 0; i <= n; i++)
        printf("%d ", a[i]);





    return 0;

}