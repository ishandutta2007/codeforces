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
int n, k, a;
vector < int > v[100];
set  < int > s;
int main () {
    cin >> n >> k;
    for(int i = 1; i<=n*k; i++)
        s.insert(i);
    for(int i = 0; i<k; i++){
        cin >> a;
        v[i].pb(a);
        s.erase(s.find(a));    
    }
    while(!s.empty()){
        for(int i = 0; i<k; i++){
            v[i].pb(*(s.begin()));
            s.erase(s.begin());
        }
    }
    for(int i = 0; i<k; i++){
        for(int j = 0; j<v[i].size(); j++) cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}