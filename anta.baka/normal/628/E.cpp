#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int N = 3000;

int n, m, l[N][N], r[N][N], d[N][N], tr[2*N][N], ans[2*N][N];
vector<int> ask[N][N];
char a[N][N];

inline void add(int t, int p) {
    for(; p < m; p |= p+1)
        tr[t][p]++;
}

inline int get(int t, int p) {
    int res = 0;
    for(; p >= 0; p = (p & (p+1)) - 1)
        res += tr[t][p];
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) {
        char ch; scanf("%c", &ch);
        for(int j = 0; j < m; j++)
            scanf("%c", &a[i][j]);
    }

    for(int i = 0; i < n; i++) {
        if(a[i][0] == 'z') {
            l[i][0] = 1;
            d[i][0] = 1;
        }
        if(a[i][m-1] == 'z')
            r[i][m-1] = 1;
    }

    for(int j = 0; j < m; j++) {
        if(a[n-1][j] == 'z') {
            d[n-1][j] = 1;
            if(j)
                l[n-1][j] = l[n-1][j-1] + 1;
        }
        if(j && a[n-1][m-j-1] == 'z')
            r[n-1][m-j-1] = r[n-1][m-j] + 1;
    }

    for(int i = n - 2; i >= 0; i--)
        for(int j = 1; j < m; j++) {
            if(a[i][j] == 'z') {
                l[i][j] = l[i][j-1] + 1;
                d[i][j] = d[i+1][j-1] + 1;
                int t = min(l[i][j], d[i][j]);
                if(i + t < n && j >= t)
                    ask[i+t][j-t].push_back(j);
            }
            if(a[i][m-j-1] == 'z')
                r[i][m-j-1] = r[i][m-j] + 1;
        }

    long long res = 0;
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++) {
            if(a[i][j] == 'z') {
                add(i+j, j + r[i][j] - 1);
                res += get(i+j, m-1) - get(i+j, j-1) - ans[i+j][j];
            }
            for(int k = 0, sz = (int)ask[i][j].size(); k < sz; k++)
                    ans[i+j][ask[i][j][k]] = get(i+j, m-1) - get(i+j, ask[i][j][k]-1);
        }

    printf("%I64d", res);
    return 0;
}