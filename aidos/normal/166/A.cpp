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
   vector < pii > v;
   int n, k;
   v.pb(mp(1000000000, 0));
   cin >> n >> k;
   for(int i = 0; i<n; i++){
        int l, r;
        cin >> l >> r;
        v.pb(mp(l, -r));
   }
   sort(v.begin(), v.end());
   reverse(v.begin(), v.end());
   int ans = 1;
   while(v[k] == v[k-1]) k--;
   //cout << k << endl;
   while(k<n && v[k+1] == v[k]){
        ans ++;
        k++;
   }
   cout << ans;
   return 0;
}