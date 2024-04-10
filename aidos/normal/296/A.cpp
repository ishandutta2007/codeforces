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
    int n, a[110], k;
    map <int, int> m;
    cin >> n;
    k = (n+1)/2;
    for(int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    for(int i=0; i<n; i++)
        if(m[a[i]]>k){
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}