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
    int n, m, k=1;
    cin >> n >> m;
    while(m>=0){
        if(k>m){
            cout << m;
            return 0;
        }
        m-=k;
        k++;
        if(k>n){
            k=1;
        }
    }
    return 0;
}