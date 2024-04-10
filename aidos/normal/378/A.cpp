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
int get(int x, int y){
    if(x <= y) return x == y;
    return 2;
}
int main () {
    int n, m, a[10];
    for(int i = 0; i<5; i++)
        a[i] = 0;
    cin >> n >> m;
    for(int i = 1; i<=6; i++){
        a[get(abs(n-i), abs(m-i))]++;
    }
    for(int i = 0; i<3; i++)
        cout << a[i] << " ";
    return 0;
}