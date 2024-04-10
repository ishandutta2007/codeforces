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
    int k, b[150100], ans = 0;
    for(int j = 0; j<150000; j++)
        b[j] = 0;
    for(int i = 0; i<4; i++){
        cin >> k;
        for(int j=k; j<120000; j+=k)
            b[j] = 1; 
    }
    cin >> k;
    for(int i = 1; i<=k; i++)
        ans += b[i];
    cout << ans;
    return 0;
}