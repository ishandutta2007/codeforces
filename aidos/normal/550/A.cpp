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
#include <ctime>

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
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    vector < int > v1, v2;
    for(int i = 1; i < s.size(); i++){
        string a = "";
        a += s[i-1];
        a += s[i];
        if(a == "AB") v1.pb(i-1);
        else if(a=="BA") v2.pb(i-1);
    }
    if(v1.size() == 0 || v2.size() == 0){
        cout << "NO";
        return 0;
    }
    if(v1.size() > 1 && v2.size() > 1){
        cout << "YES\n";
        return 0;
    }
    if(v1.size() > v2.size()) swap(v1, v2);
    for(int i = 0; i < v2.size(); i++){
        if(abs(v2[i] - v1[0]) != 1){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO";



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}