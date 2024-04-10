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
   ll n, f[50];
   f[0] = 0;
   f[1] = 1;
   cin >> n;
   for(int i = 2; i < 46; i++){
        f[i] = f[i-1] + f[i-2];
   }
   for(int i = 0; i<46; i++)
        for(int j = 0; j < 46; j++)
            for(int k = 0; k<46; k++){
                if(f[i] + f[j] + f[k] == n){
                    cout << f[i] << " " << f[j] << " " << f[k];
                    return 0;
                }
            }
   cout << "I'm too stupid to solve this problem";
   return 0;
}