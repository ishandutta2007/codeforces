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
    int a, b, n, k = 1;
    cin >> a >> b >> n;
    while(n){
        if(k){
            n-=__gcd(a, n);
        }
        else {
            n-=__gcd(b, n);
        }
        k=1-k;
    }
    cout << k;
    return 0;
}