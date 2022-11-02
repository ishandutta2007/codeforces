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
    int n, k, l = 0;
    cin >> n >> k;
    if(n<k || k>26 || (k==1 && n!=1)){
        cout << -1;
        return 0;
    }
    string s = "";
    int t = n-k+2;
    if(k==1){
        cout << 'a';
        return 0;
    }
    if(k==2){
        for(int i = 0; i < n; i++){
          if(l) cout << 'b';
           else cout << 'a';
            l = 1-l;
        }
        return 0;
    }
    for(int i = 0; i < t; i++){
        if(l) cout << 'b';
        else cout << 'a';
        l = 1-l;
    }
    char d = 'a';
    for(int i = 2; i<k; i++)
        cout << (char)(d+i);                        
    return 0;
}