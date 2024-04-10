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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    set <int> s;
    map <int, int> m;
    int n, k, km = -1;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> k;
        m[k] ++;
        s.insert(k);
        km = k;
    }
    bool x = 1;
    while(x){
        for(set <int> :: iterator it = s.begin(); it!=s.end(); it++){
            int z = *it;
            if(m[z]>1){
                m[z+1] += (m[z]/2);
                s.insert(z+1);
                m[z] %=2;
                km = max(z+1, km);
            }
        }
        x = 0;               
        for(set <int> :: iterator it = s.begin(); it!=s.end(); it++)
            if( m[*it] > 2) x = 1;            
    }
    for(set <int> :: iterator it = s.begin(); it!=s.end(); it++)
        if(m[*it]==1) km--;
    cout << km+1;
    return 0;
}