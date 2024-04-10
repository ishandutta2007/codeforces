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
bool check(int x){
    while(x){
        if(x%10 == 4 || x % 10 == 7){
            x/=10;
            continue;
        }
        return 0;
    }
    return 1;
} 
int main () {
    int x, n, a[111];
    cin >> n;
    for(int i=2; i<=n; i++){
        if(n%i == 0 && check(i)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}