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
    vector <bool> v(4000, 1);
    int n, x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        v[x] = 0;        
    }
    for(int i = 1; ; i++)
        if(v[i]){
            cout << i;
            return 0;
        }
    return 0;
}