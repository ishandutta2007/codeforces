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
    int n, a[1111];
    map < int, int > m;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        m[a[i]] = i+1;
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(m[a[i]+a[j]]!=0){
                cout << m[a[i] + a[j]] << " " << i+1 <<" " << j+1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}