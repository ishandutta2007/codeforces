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
    int n, m, ans = 0, maxn = -1, a[111], b[111];
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    } 
    cin >> m;
    for(int j = 0; j<m; j++){
        cin >> b[j];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(b[j] % a[i] == 0){
                if(b[j]/a[i]>maxn){
                    maxn=b[j]/a[i];
                    ans = 1;
                }
                else if(b[j]==maxn*a[i]){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}