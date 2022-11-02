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
    int n, s[10], k, ans = 0;
    for(int i = 0; i<7; i++)
        s[i] = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> k;
        s[k]++;
    }
    ans += s[4];
    int x = min(s[1], s[3]);
    s[1]-=x;
    s[3]-=x;
    ans += x;
    ans+=s[3];
    ans += s[2]/2;
    ans += s[1]/4;
    s[1] %= 4;
    s[2]%=2;
    if(s[1] == 3) {
        ans += 1;
        s[1] = 0;
    }
    if(s[2] == 1) {
        ans++;
        s[2]=0;
        s[1] = 0;
    }
    if(s[1]) ans++;
    cout << ans;
    return 0;
}