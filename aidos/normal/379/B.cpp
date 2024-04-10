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
    int n, a[310];
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    int k = 0;
    while(k < n){
        if(k == n-1){
            while(a[k] > 0){
                printf("LRP");
                a[k]--;
            }
        }
        else {
            while(a[k] > 0){
                printf("RLP");
                a[k]--;
            }
            printf("R");
        }
        k++;
    }
    return 0;
}