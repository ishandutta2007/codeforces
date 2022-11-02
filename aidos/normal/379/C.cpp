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
    int a, b[300100], n;
    scanf("%d", &n);
    vector < pii > v;
    for(int i = 0; i<n; i++){
        scanf("%d", &a);
        v.pb(mp(a, i));
    }
    sort(v.begin(), v.end());
    b[v[0].sc] = v[0].ff;
    for(int i = 1; i<n; i++){
        b[v[i].sc] = max(b[v[i-1].sc]+1, v[i].ff);
    }
    for(int i=0; i<n; i++)
        printf("%d ", b[i]);
    return 0;
}