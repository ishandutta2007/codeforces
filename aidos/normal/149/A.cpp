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
    int k, b[15], ans = 0, l = 0;
    cin >> k;
    for(int i = 0; i<12; i++)
        cin >> b[i];
    sort(b, b+12);
    for(int i = 11; i>=0; i--){
        if(ans>=k) break;
        ans+=b[i];
        l++;
    }
    if(ans>=k) cout << l;
    else cout << -1;
    return 0;
}