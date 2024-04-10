#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
    int b[21000], a[21000], n, maxn = -1000000000;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            int x = n/i;
            if(i > 2) {
                for(int j = 0; j<x; j++)
                    b[j] = a[j];
                for(int j = x; j<n; j++){
                    b[j] = b[j-x] + a[j];
                }
                for(int j = n-x; j<n; j++)
                    if(maxn < b[j]) maxn = b[j];
            }
            if(x > 2) {
                for(int j = 0; j<i; j++)
                    b[j] = a[j];
                for(int j = i; j<n; j++){
                    b[j] = b[j-i] + a[j];
                }
                for(int j = n-i; j<n; j++)
                    if(maxn < b[j]) maxn = b[j];
            }
        }
    }
    printf("%d", maxn);
    return 0;
}