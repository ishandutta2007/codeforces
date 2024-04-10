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
    int a[110000], b[110000], n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++)
        a[i]=1;
    a[n] = 0;
    for(int i=0; i<k; i++){
        for(int j = 1; j<=n; j++)
            if(a[j]*2<=n-j) {
                cout << j << " ";
                a[j]*=2;
            }
            else {
                cout << j+a[j] <<  " ";
                a[j] = n-j;
            }
            cout << endl;
    }
        
    return 0;
}