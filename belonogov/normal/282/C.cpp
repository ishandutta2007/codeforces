#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = -1;
const int inf = (int)1e9;

string s1, s2;

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, cnt1 = 0, cnt2 = 0;
    cin >> s1;
    cin >> s2;
    n = s1.length();
    m = s2.length();
    if (n != m){
        cout << "NO\n";
        return 0;
    }
    if (s1 == s2){
        cout << "YES\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
        cnt1 += s1[i] == '1';
    
    for(int i = 0; i < n; i++)
        cnt2 += s2[i] == '1';
    if (cnt1 == 0 || cnt2 == 0)
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}