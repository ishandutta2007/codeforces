#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e5;

typedef long long ll;
typedef double db;
int a[100][100];
string s;

int main(){
    int n, i, j, x, y, ans, m;
    cin >> n;
    forn(i, n){
        cin >> s;
        m = s.length();
        x = s[0] - 'a';
        y = s[m - 1] - 'a';
        forn(j, 26){
            if (a[j][x] != 0)
                a[j][y] = max(a[j][y], a[j][x] + m);
        }
        a[x][y] = max(a[x][y], m);      

    }
    ans = 0;
    forn(i, 26)
        ans = max(ans, a[i][i]);

    cout << ans;
    return 0;

}