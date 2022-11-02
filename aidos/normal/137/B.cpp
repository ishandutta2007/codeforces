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
int n, a[5555];
int main () {
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    int ans = 0;
    for(int i = 1; i<=n; i++)
        ans += a[i];
    cout << n - ans;
        
    return 0;
}