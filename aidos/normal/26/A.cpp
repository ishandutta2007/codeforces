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
    int n, k, t = 0, z;
    cin >> n;
    for(int i=6; i<=n; i++){
        k = i;
        z = 2;
        vector <int> v;
        while(k!=1){
            if(k%z==0){
                while(k%z==0){
                    k/=z;
                }
                v.push_back(z);                        
            }
            z++;
        }
        if(v.size()==2) t++;
    }
    cout << t;
    return 0;
}