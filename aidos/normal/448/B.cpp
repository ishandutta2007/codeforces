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
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;
string a, b;
int c[3][27];
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++){
        c[0][a[i] - 'a']++;
    }
    for(int j = 0; j < b.size(); j++){
        c[1][b[j]-'a']++;
    }
    int l = -1;
    int ok = 1;
    for(int i = 0; i < b.size(); i++){
        l++;
        while( l < a.size() && b[i] != a[l]) l++;
        if( l == a.size())ok=0;
    }
    if(ok){
        cout << "automaton\n";
        return 0;
    }
    ok = 1;
    for(int i = 0; i < 26; i++){
        if( c[0][i] != c[1][i]) ok= 0;
    }
    if( ok ){
        cout << "array\n";
        return 0;
    }
    ok = 1;
    for(int i =0; i < 26; i++){
        if( c[0][i] < c[1][i] ) ok = 0;
    }
    if( ok ) {
        cout << "both\n";
        return 0;
    }
    cout << "need tree";

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}