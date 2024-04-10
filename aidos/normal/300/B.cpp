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
    vector <int> v[100];
    int n, a[100], k[3000], l[3000], m, z = 1;
    for(int i=0; i<90; i++)
        a[i] = 0;    
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> k[i] >> l[i];    
    }
    for(int i=0; i<m; i++){
        if(a[k[i]] == 0){
            if(a[l[i]] == 0){
                a[k[i]] = z;
                a[l[i]] = z;
                v[z].pb(l[i]);
                v[z].pb(k[i]);
                z++;
            }
            else {
                a[k[i]] = a[l[i]];
                v[a[l[i]]].pb(k[i]);                
            }
        }
        else {
            if(a[l[i]] == 0){
                a[l[i]] = a[k[i]];
                v[a[k[i]]].pb(l[i]);
            }
            else if(a[l[i]]!=a[k[i]]){
                cout << -1;
                return 0;
            }
        }
    }
    int s = n/3;
    for(int i=1; i<=n; i++){
        if(a[i]==0)
            for(int j=1; j<=s; j++){
                if(v[j].size()<3){
                     v[j].pb(i);
                    break;
                }
            }
    }
    for(int i = 1; i<=s; i++)
        if(v[i].size()!=3){
            cout << -1;
            return 0;
        }
    for(int i=1; i<=s; i++){
        for(int j=0; j<3; j++)
            cout << v[i][j] <<  " ";
        cout << endl;
    }
    return 0;
}