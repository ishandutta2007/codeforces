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

#define MAXN (int) (1e7)
using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    int n, p;
    string s;
    cin >> n >> p >> s;

    for(int i = n-1; i>=0; i--){
        for(char c = s[i] + 1; c < 'a' + p; c++){
            if( i!= 0 && s[i-1] == c) continue;
            if( i>1 && s[i-2] == c) continue;
            s[i] = c;
            for(int j = 0; j <= i; j++) cout << s[j];
            for(int j = i+1; j < n; j++){
                char x='a';
                while( j > 0 && s[j-1] == x || j > 1 && s[j-2] == x) x++;
                s[j] = x;
                cout << x;
            }
            cout<< endl;
            return 0;
        }
    }

    cout << "NO";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}