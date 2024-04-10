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
    int n, a[10000], t=0;
    map <int, int> m;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]!=0)m[a[i]]++;
    }
    for(int i=0; i<n; i++)
        if(m[a[i]]==2) t++;
        else if(m[a[i]]>2){
            cout << -1;
            return 0;
        }
    cout << t/2;
    return 0;
}