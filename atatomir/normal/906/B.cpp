#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, m, i, j, p;
vector< vector<int> > ans;
int act[maxN];
map< pair<int, int>, bool > M;

void no_sol() {
    printf("NO");
    exit(0);
}

int main() {
    
    scanf("%d%d", &n, &m);
    ans = vector< vector<int> >(n + 3, vector<int>(m + 3, 0));
    
    if (n == 3 && m == 3) {
        printf("YES\n");
        printf("1 6 8\n");
        printf("7 2 4\n");
        printf("5 9 3\n");
        return 0;
    }

    for (i = 1; i <= n; i++) 
        for (j = 1; j <= m; j++)
            ans[i][j] = (i - 1) * m + j;
            
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i < n) {
                M[mp(ans[i][j], ans[i + 1][j])] = true;
                M[mp(ans[i + 1][j], ans[i][j])] = true;
            }
            
            if (j < m) {
                M[mp(ans[i][j + 1], ans[i][j])] = true;
                M[mp(ans[i][j], ans[i][j + 1])] = true;
            }
        }
    }
     
    if (m > n) {       
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) act[j] = ans[i][j];
            
            p = 2;
            for (j = 1; j <= m; j++) {
                if (p > m) p = 1;
                ans[i][p] = act[j];
                p += 2;
            }
            
            if (i & 1) {
                if (m & 1) {
                    ans[i][m + 1] = ans[i][1];
                     for (j = 1; j <= m; j++) ans[i][j] = ans[i][j + 1];
                } else {
                    int p1 = 1;
                    int p2 = m;
                    while (p1 < p2) {
                        swap(ans[i][p1], ans[i][p2]);
                        p1++; p2--;
                    }
                }
            }
        }
    } else {
    
        for (j = 1; j <= m; j++) {
            for (i = 1; i <= n; i++) act[i] = ans[i][j];
            
            p = 2;
            for (i = 1; i <= n; i++) {
                if (p > n) p = 1;
                ans[p][j] = act[i];
                p += 2;
            }
            
            if (j & 1) {
                if (n & 1) {
                    ans[n + 1][j] = ans[1][j];
                    for (i = 1; i <= n; i++) ans[i][j] = ans[i + 1][j];
                } else {
                    int p1 = 1;
                    int p2 = n;
                    while (p1 < p2) {
                        swap(ans[p1][j], ans[p2][j]);
                        p1++; p2--;
                    }
                }
            }
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (M[mp(ans[i][j], ans[i + 1][j])] && i < n) no_sol();
            if (M[mp(ans[i][j], ans[i][j + 1])] && j < m) no_sol();
        }
    }
    
    printf("YES\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
    
    
    
    
    return 0;
}