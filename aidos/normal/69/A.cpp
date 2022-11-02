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
    int x[11], a[11], n;
    cin >> n;
    x[0] = x[1] = x[2] = 0;
    for(int i = 0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> a[j];
            x[j] += a[j];
        }
    }
    for(int i = 0; i<3; i++){
       if(x[i]!= 0){
            cout << "NO";
            return 0;
       }
    }
    cout << "YES";
    return 0;
}