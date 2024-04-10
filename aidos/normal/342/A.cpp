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
    int n, a[10], k;
    for(int i = 0; i<9; i++)
        a[i] = 0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> k;
        a[k]++;
    }
    if(a[5] || a[7] || a[1] != a[4] + a[6] || a[1]+a[2]<a[4] || a[2] + a[3] != a[1] || a[3] > a[6] || a[2]+a[3] < a[6] || a[4] > a[2]){
        cout << -1;
        return 0;
    }
    while(a[4]){
        cout << "1 2 4\n";
        a[1]--;
        a[2]--;
        a[4]--;
    }
    while(a[2]){
        cout <<"1 2 6\n";
        a[1]--;
        a[2]--;
        a[6]--;
    }
    while(a[6]){
        cout <<"1 3 6\n";
        a[3]--;
        a[1]--;
        a[6]--;
    }

	return 0;
}