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

const int maxn = -1;
const int inf = (int)1e9;

string s;

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int k = 0, n;
    cin >> n;
    cin >> s;
    for(int i = 0; i < (int)(s.length() - 1); i++)
        if (s[i] == s[i + 1])
            k++;
    cout << k << endl;
        
        
    return 0;
}