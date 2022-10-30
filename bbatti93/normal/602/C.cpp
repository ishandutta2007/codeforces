#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

int n, m, t[401][401];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1; j<=n;j++) {
            t[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        t[b][a]=t[a][b]=1;
    }
    if(t[1][n]==1) {
        for(int i=1;i<=n;i++) {
            for(int j=1; j<=n;j++) {
                t[i][j]=INF+1-t[i][j];
            }
        }
    }
    for(int k=1;k<=n;k++) {
        for(int j=1;j<=n;j++) {
            for(int i=1;i<=n;i++) {
                if(t[i][j]>t[i][k]+t[k][j]) {
                    t[i][j]=t[i][k]+t[k][j];
                }
            }
        }
    }
    if(t[1][n]==INF) t[1][n]=-1;
    cout << t[1][n] << endl;
    return 0;
}