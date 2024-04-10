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
    int n, k, a[100],l = 0;
    cin >> n >> k;
    for(int i = 0; i<k; i++)
        cin >> a[i];
    sort(a, a+k);
    for(int i = n; i<k; i++){
        if(a[i]-a[i-n+1] < a[l+n-1]-a[l]){
            l = i-n+1;            
        }
    }
    cout << a[l+n-1] - a[l];
    return 0;
}