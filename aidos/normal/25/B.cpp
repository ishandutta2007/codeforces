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
    int n, i = 0;
    char c[300];
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> c[i];
    bool ok = 0;
    if(n%2){
        cout << c[0] << c[1] << c[2];
        ok = 1;
        i+=3;        
    }
    for( ; i<n; i+=2){
        if(ok) cout << '-';
        cout << c[i] << c[i+1];
        ok = 1;
    }
    return 0;
}