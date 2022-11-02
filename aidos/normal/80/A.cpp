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
vector < bool > p(111, 0);
vector < int > a(111, 0);
int main () {
    for(int i = 2; i<60; i++){
        a[i] = a[i-1];
        if(!p[i]){
            for(int j=i+i; j<60; j+=i)
                p[j] = 1;
            a[i]++;
        }
    }
    int n, m;
    cin >> n >> m;
    if(!p[n] && !p[m] && (a[m] - a[n] == 1)){
        cout << "YES";    
    }
    else cout << "NO";

    return 0;
}