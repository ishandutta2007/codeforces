#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 5000 + 2;
const int inf = 1e9;


char a[maxn][maxn];
int b[maxn][maxn];
int c[maxn];
/*
inline bool cmp(const int & a, const int & b){
    return a > b;   
}*/
template <class T> struct greater1 : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x>y;}
};


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf(" %s", a[i]);
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--){
            if (a[i][j] == '1')
                b[i][j] = b[i][j + 1] + 1;
            else
                b[i][j] = 0;        
        }

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++)
            c[i] = b[i][j];
        sort(c, c + n, greater1<int>());
        
        for (int i = 0; i < n; i++)
            ans = max(ans, (i + 1) * c[i]);         
    }
    cout << ans << endl;
     for (int i = 0; i < 10000000; i++)
         printf("\n");
    return 0;
}