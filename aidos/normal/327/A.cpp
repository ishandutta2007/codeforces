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
    int n, sum = 0, ans = 0, a[111], b[111];
    cin >> n;
    b[0] = 0;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
        b[i] = b[i-1] + a[i];
        sum+=a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            ans = max(ans, sum - 2*(b[j] - b[i-1]) + j-i+1);
        }
    }
    cout << ans;
    return 0;
}