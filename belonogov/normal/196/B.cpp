#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

const int maxn = 2e3;

typedef long long ll;
typedef double db;


int a[maxn][maxn];
bool use[maxn][maxn];
pair < int, int > b[maxn][maxn];
int n, m;

//void hod(int 

void dfs(int x, int y, int x1, int y1){
    use[x][y] = 1;
    b[x][y] = make_pair(x1, y1);
    
    if (a[(x + n + 1) % n][(y + m) % m]){
        if (! use[(x + n + 1) % n][(y + m) % m])
            dfs((x + n + 1) % n, (y + m) % m, x1 + (x + n + 1) / n - 1, y1 + (y + m) / m - 1);
        else
            if (b[(x + n + 1) % n][(y + m) % m] != make_pair(x1 + (x + n + 1) / n - 1, y1 + (y + m) / m - 1)){
                cout << "Yes";
                exit(0);
            }
    }

    if (a[(x + n - 1) % n][(y + m) % m]){
        if (! use[(x + n - 1) % n][(y + m) % m])
            dfs((x + n - 1) % n, (y + m) % m, x1 + (x + n - 1) / n - 1, y1 + (y + m) / m - 1);
        else
            if (b[(x + n - 1) % n][(y + m) % m] != make_pair(x1 + (x + n - 1) / n - 1, y1 + (y + m) / m - 1)){
                cout << "Yes";
                exit(0);
            }
    }
    
    if (a[(x + n) % n][(y + m + 1) % m]){
        if (! use[(x + n) % n][(y + m + 1) % m])
            dfs((x + n) % n, (y + m + 1) % m, x1 + (x + n) / n - 1, y1 + (y + m + 1) / m - 1);
        else
            if (b[(x + n) % n][(y + m + 1) % m] != make_pair(x1 + (x + n) / n - 1, y1 + (y + m + 1) / m - 1)){
                cout << "Yes";
                exit(0);
            }
    }   
    
    if (a[(x + n) % n][(y + m - 1) % m]){
        if (! use[(x + n) % n][(y + m - 1) % m])
            dfs((x + n) % n, (y + m - 1) % m, x1 + (x + n) / n - 1, y1 + (y + m - 1) / m - 1);
        else
            if (b[(x + n) % n][(y + m - 1) % m] != make_pair(x1 + (x + n) / n - 1, y1 + (y + m - 1) / m - 1)){
                cout << "Yes";
                exit(0);
            }
    }

}

int main(){
    int i, j, x, y;
    char ch;
    scanf("%d %d\n", &n, &m);
    forn(i, n){
        forn(j, m){
            scanf("%c", &ch);
            if (ch == '.')
                a[i][j] = 1;
            if (ch == 'S'){
                a[i][j] = 1;
                x = i;
                y = j; 
            }
        }
        scanf("\n");
    }
    dfs(x, y, 0, 0);
    cout << "No";
    return 0;

}