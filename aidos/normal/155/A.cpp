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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std;
int main () {
    int n, mn, mx, k, ans = 0;
    cin >> n >> k;
    mn = mx = k;
    for(int i=1; i<n; i++){
        cin >> k;
        if(k<mn){
            mn = k;
            ans ++;
        }
        if(k>mx){
            mx = k;
            ans++;
        }
    }
    cout << ans;
    return 0;
}