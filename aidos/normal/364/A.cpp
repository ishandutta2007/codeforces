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
	map < int, int > m;
    int a, x, d[100100], t = 0, u = 0;
    string s;
    cin >>a >> s;
    x = s.size();
    d[0] = 0;
    for(int i = 1;i<=x; i++)
        d[i] = d[i-1] + s[i-1] - '0';
    for(int i = 1; i<=x; i++)
        for(int j=1; j<=i; j++){
            m[d[i]-d[j-1]]++;
        }
    x *= 9;
    ll ans = 0;
    for(int i = 1; i<=x; i++){
        if(a % i == 0){
            int z = a/i;
            ans += m[z] * 1ll * m[i];
            if(a == 0)ans += m[z] * 1ll * m[i];
        }
    }
    if(a == 0){
        ans += m[0] * 1ll*m[0];
    }
    cout << ans;
    return 0;
}