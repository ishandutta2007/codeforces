/**
 *    author:  SPb ITMO University 1
 *    created: 27.10.2016 10:39:49       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */



int main()
{
    #ifdef home
        //assert(freopen("1.in", "r", stdin));
        //assert(freopen("1.out", "w", stdout));
    #endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> mn, mx;
        for (int i = 1; i <= n; i += 2) {
            if (i == n) {
                mn.push_back(i);
                mx.push_back(i);
            } else {
                cout << "? " << i << " " << i + 1 << endl;
                char c;
                cin >> c;
                if (c == '<') mn.push_back(i), mx.push_back(i + 1);
                else mn.push_back(i + 1), mx.push_back(i);
            }
        }
        int curmn = mn[0];
        for (int i = 1; i < (int)mn.size(); i++) {
            cout << "? " << curmn << " " << mn[i] << endl;
            char c;
            cin >> c;
            if (c == '>') curmn = mn[i];
        }
        int curmx = mx[0];
        for (int i = 1; i < (int)mx.size(); i++) {
            cout << "? " << curmx << " " << mx[i] << endl;
            char c;
            cin >> c;
            if (c == '<') curmx = mx[i];
        }
        cout << "! " << curmn << " " << curmx << endl;
    } 


    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}