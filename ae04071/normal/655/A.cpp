#include <bits/stdc++.h>
using namespace std;

char str[2][5][5];
int n=2;

int dy[2][2]={{0,1},{-1,0}},dx[2][2]={{1,0},{0,-1}};

int main() {
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) scanf("%s",str[i][j]);

    for(int t=0;t<20;t++) {
        int f=1;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++) if(str[0][i][j]!=str[1][i][j]) {
            f=0;
            break;
        }
        if(f) {
            puts("YES");
            return 0;
        }
        for(int i=0;i<n&&!f;i++)for(int j=0;j<n;j++) if(str[0][i][j]=='X') {
            int y=i+dy[i][j],x=j+dx[i][j];
            swap(str[0][i][j],str[0][y][x]);
            f=1;
            break;
        }
    }
    puts("NO");
    
    return 0;
}