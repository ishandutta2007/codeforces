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


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = (int)2e6;
const int inf = (int)1e9;

string s;
int a[maxn];

int main(){
//     freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, l, r;
    cin >> s;
    n = s.length();
    l = 0;
    r = n - 1;
    for(int i = 0; i < n; i++)
        if (s[i] == 'l')
            a[r--] = i + 1;
        else
            a[l++] = i + 1;
        
    for(int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    
    
    

    return 0;
}