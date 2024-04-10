#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e5;

typedef long long ll;
typedef double db;

char a[100][100];
bool use[100][100];
int n, m;
void dfs(int x, int y, int prx = -1, int pry = -1);

bool cor(int x, int y){
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void hod(int x, int y, int prx, int pry, int i, int j){
    if (! cor(x, y))
        return;
    if (x == prx && y == pry)
        return;
    if (use[x][y] || a[x][y] == '.'){
        return;
    }
    dfs(x, y, i, j);
}

void dfs(int x, int y, int prx, int pry){
    use[x][y] = true;
//  if (cor(x, y) && (x != prx || y != pry) && !use[x][y] && a[x][y] == '#')
    hod(x + 1, y, prx, pry, x, y);
    hod(x - 1, y, prx, pry, x, y);
    hod(x, y + 1, prx, pry, x, y);
    hod(x, y - 1, prx, pry, x, y);
}


int main(){
   int cnt = 0, i, j, i1, j1, kol;
    scanf("%d %d\n", &n, &m);
    forn(i, n){
        forn(j, m){
            scanf("%c", &a[i][j]);
            if (a[i][j] == '#'){
                cnt++;
                i1 = i;
                j1 = j;
            }
        }
        scanf("\n");
    }
    if (cnt <= 2){
        cout << -1;
        return 0;
    }
    forn(i, n)
        forn(j, m){
            if (a[i][j] == '.')
                continue;
            a[i][j] = '.';
            kol = 0;
            memset(use, 0, sizeof(use));
            forn(i1, n)
                forn(j1, m)
                if (a[i1][j1] == '#' && ! use[i1][j1]){
                    dfs(i1, j1);
                    kol++;
                }
            if (kol > 1){
                cout << 1;
                return 0;
            }
            a[i][j] = '#';
        }   
    cout << 2;

    return 0;

}