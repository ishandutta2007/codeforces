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
    string s, t;
    cin >> s;
    int a = s.size();
    t += '/';
    while(a>0 && s[a-1] == '/') a--;
    for(int i = 1; i<a; i++)
        if(s[i] == '/'){
            if(s[i-1]!='/') t+='/';
        }
        else t += s[i];
    cout << t;
    return 0;
}