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
int a[111], n, x;
int main () {
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x;
        a[x]++;
    }
    set < pii > s;
    for(int i = 1; i<105; i++){
        if(a[i] > 1) s.insert(mp(a[i], i));
    }
    int ans = 0;
    while(s.size() > 1){
        pii a = *s.begin();
        s.erase(s.begin());
        pii b = *s.begin();
        s.erase(s.begin());
        ans++;
        a.ff -= 2;
        b.ff -= 2;
        if(a.ff > 1) s.insert(a);
        if(b.ff > 1) s.insert(b);
    }
    if(s.size() == 1){
        ans += (s.begin()->ff)/4;
    }              
    cout << ans;
    return 0;
}