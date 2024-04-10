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
bool ok(string s, int k){
    for(int i = 0; i <= k; i++){
        int d = 0;
        for(int j=0; j<s.size(); j++){
            if(s[j] == i+'0') d = 1; 
        }
        if(!d) return 0;
    }
    return 1;
}
int main () {
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        if(ok(s, k)) ans++;
    }
    cout << ans;
    return 0;
}