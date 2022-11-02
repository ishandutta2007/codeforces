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
    string s[111];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        cin >> s[i];
    for(int i = 0; i<n; i++)
        for(int j = 1; j<m; j++)
            if(s[i][j] != s[i][j-1]){
                cout << "NO";
                return 0;
            }
    for(int i=1; i<n; i++)
        if(s[i][0] == s[i-1][0]){
            cout << "NO";
            return 0;
        }
    cout << "YES";
    return 0;
}