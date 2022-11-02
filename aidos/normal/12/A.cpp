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
    string s[10];
    cin >> s[0] >> s[1] >> s[2];
    int k = 0;
    if(s[0][0] == s[2][2])  k++;
    if(s[0][1] == s[2][1]) k++;
    if(s[0][2] == s[2][0]) k++;
    if(s[1][0] == s[1][2]) k++;
    if(k == 4) cout << "YES";
    else cout << "NO";
    return 0;
}