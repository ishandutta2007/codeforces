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
vector <int> v[80];
vector <bool> b(100, 1);
int a = 0, c = 0;
void dfs(int x){
    b[x] = 0;
    int t = v[x].size();
    for(int i=0; i<t; i++)
        if(v[x][i]==c){
            cout << a << " " << c;
            exit(0);
        }        
        else if(b[v[x][i]]) dfs(v[x][i]);
}
int main () {   
    int n, x, d, z;
    cin >> n;
    map <int, int> m;
    z = n*(n-1)/2-1;
    for(int i = 0; i<z; i++){
        cin >> x >> d;
        v[x].pb(d);
        m[x]++;
        m[d]++;
    }
    for(int i=1; i<=n; i++)
        if(m[i]==n-2){
            if(!a) a = i;
            else c=i;
        }
    dfs(a);
    cout << c << " " << a;
    return 0;
}