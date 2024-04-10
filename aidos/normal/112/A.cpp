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
#define pll pair <long long,long long>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define MAXN 1000000
#define INF 1000000000
using namespace std; 
int main () {
    string s;
    cin >> s;
    int n = s.size();
    vector < int > v;
    for(int i = 0; i<n; i++)
        if(s[i]>='A' && s[i] <= 'Z')v.pb(s[i]-'A');
        else v.pb(s[i]-'a');
    cin >> s;
    vector < int > u;
    for(int i = 0; i<n; i++)
        if(s[i]>='A' && s[i] <= 'Z')u.pb(s[i]-'A');
        else u.pb(s[i]-'a');
    for(int i = 0; i<n; i++){
        if(v[i] == u[i]) continue;
        if(v[i]>u[i]) cout << 1;
        else cout << -1;
        return 0;
    }
    cout << 0;
    return 0;
}