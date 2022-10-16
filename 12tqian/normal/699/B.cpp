#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
static int a [MAX][MAX];
static int r [MAX];
static int c[MAX];
int main(){
    int n, m;
    int total = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int x = 0; x<m; x++){
            if(s[x] == '*'){
                a[i][x] = 1;
                r[i] += 1;
                c[x] += 1;
                total += 1;
            }
        }
    }
    for(int x = 0; x<n; x++){
        for(int y = 0; y<m; y++){
            if(r[x] + c[y] - a[x][y] == total){
                cout << "YES" << endl;
                cout << x + 1 << " " << y + 1;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}