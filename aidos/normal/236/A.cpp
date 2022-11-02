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
    int n = s.size(), k = 0;
    set < char > x;
    for(int i = 0; i<n; i++)
        x.insert(s[i]);
    if((x.size())%2 == 1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
    return 0;
}