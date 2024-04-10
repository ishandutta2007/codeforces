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
    int x, n, a[111];
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> x;
        a[x] = i;
    }
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
    return 0;
}