#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

const int maxn = 2e5;
ll a[maxn];
ll b[maxn];

int main(){
    ll s, n;
    int i, k;
    cin >> s >> k;
    a[0] = 1;
    for(i = 1; a[i - 1] < s; i++){
        for(int j = max(0, i - k); j < i; j++)
            a[i] += a[j];
    }
    n = i;
    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if (a[i] <= s){
            b[ans++] = a[i];
            s -= a[i];
        }
    }
    b[ans++] = 0;
    cout << ans << endl;
    forn(i, ans)
        cout << b[i] << " ";
  
   
    return 0;
}