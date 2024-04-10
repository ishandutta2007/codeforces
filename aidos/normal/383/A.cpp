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
    int n, l = 1, r, a[211000], sum[211000];
    cin >> n;
    ll ans = 0;
    sum[0] = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    r = n;
    while(l <= r){
        while(a[l] == 0 && l <= r) l++;   
        if(l > r) break;
        while(a[r] == 1 && l <= r) r--;
        if(l > r) break;
        if(r-l-(sum[r] - sum[l]) <= sum[r-1] - sum[l-1]){
            ans+=r-l-(sum[r] - sum[l]);
            l++;
        }
        else {
            ans+=sum[r-1] - sum[l-1];
            r--;
        }
    }
    cout << ans;                    
    return 0;
}