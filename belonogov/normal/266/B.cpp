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
    int n, t;
    cin >> n >> t;
    cin >> s;
    for(int tt = 0; tt < t; tt++)
        for(int i = 0; i < n - 1; i++)
            if (s[i] == 'B' && s[i + 1] == 'G'){
    swap(s[i], s[i + 1]);
    i++;
            }
    cout << s << endl;
        
    return 0;
}