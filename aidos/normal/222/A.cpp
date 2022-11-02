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
    int n, k, a[111000], ans = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i = k+1; i<=n; i++){
        if(a[i] != a[k]) {
            cout << -1;
            return 0;
        }
    }
    for(int i = k-1; i>0; i--){
        if(a[i] != a[k]){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}