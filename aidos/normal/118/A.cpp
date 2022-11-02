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
bool check(char c){
    if(c>='A' && c <= 'Z') c = c - 'A' + 'a';
    return c == 'a' || c == 'o'||c == 'y'||c == 'e'||c == 'u'||c == 'i';
}
int main () {
    vector < char > v;
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(check(s[i])) continue;
        v.pb('.');
        if(s[i]>='A' && s[i]<='Z') v.pb(s[i] - 'A' + 'a');
        else v.pb(s[i]);
    }
    n = v.size();
    for(int i = 0; i<n; i++)
        cout << v[i];
    return 0;
}