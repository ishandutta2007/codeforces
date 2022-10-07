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


const int maxn = -1;


int main(){
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k > n){
        cout << "-1\n";
        return 0;
    }
    if (n >= 2 && k == 1){
        cout << "-1\n";
        return 0;
    }
    if (k == 1){
        printf("a\n");
        return 0;
    }
    for(int i = 0; i < n - k + 2; i++)
        printf("%c", 'a' + (i % 2));
    for(int i = n - k + 2; i < n; i++)
        printf("%c", i - (n - k) + 'a');
    printf("\n");




    return 0;

}