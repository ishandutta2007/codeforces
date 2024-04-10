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
    string s;
    cin >> s;
    int prev = -1, n = s.size()-1, ok = 0, ans = 0;
    while(n >= 0){
        while((prev == -1 || prev == s[n]) && ok < 5){
            ok++;
            prev = s[n];
            n--;    
        }
        ans++;
        ok = 0;
        prev = -1;
    }
    cout << ans;
    return 0;
}