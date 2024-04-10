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
    int n;
    cin >> n;
    if(n < 3) cout << -1;
    else {
        cout << "2 3 "; 
        for(int i = 2; i<n; i++)
            cout << "1 ";
    }
    return 0;
}