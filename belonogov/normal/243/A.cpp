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
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef vector < int > vi;

const int maxn = 2e5;
const int maxlogn = 22;

const int inf = 1e9;

int a[maxn];
int b[maxn][maxlogn];
pair < int, int > d[maxn];
set < int > st;

int main(){
    int n, x, uk, pos, day;
    scanf("%d", &n);
    forn(i, n)
        scanf("%d", &a[i]);
    
    for(int j = 0; j < maxlogn; j++){
        pos = -1;
        for(int i = n - 1; i >= 0; i--){
            if ((a[i] & (1 << j)) != 0)
    pos = i;
            b[i][j] = pos;
        }
    }
    forn(i, n){
        x = a[i];
        uk = 0;
        forn(j, maxlogn)
            if (b[i][j] != -1){
    d[uk++] = mp(b[i][j], j);
            }
        sort(d, d + uk);
    /*    cerr << "uk " << uk << endl;
        forn(j, uk)
            cerr << "f " << d[j].ff << " s " << d[j].ss << endl;
    */    st.insert(x);
        for(int j = 0; j < uk; ){
            day = d[j].ff;
            for(; j < uk && ( d[j].ff == day); j++){
    x = x | (1 << d[j].ss);
            }
            st.insert(x);
//             cerr << "x " << x << endl;
        }

    }
    cout << st.size() << endl;
    
    
    

    return 0;
}