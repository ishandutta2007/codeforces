#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n,m,q;
char a[507][507];
int d[251][500][500];
bool check(int x, int y, int s){
    if(x-s<0||y-s<0||x+s>n||y+s>m) return 0;
    for(int i=x-s;i<x;i++){
        if(a[i][y-s]!='R') return 0;
        if(a[i][y+s-1]!='G') return 0;
    }
    for(int i=x;i<x+s;i++){
        if(a[i][y-s]!='Y') return 0;
        if(a[i][y+s-1]!='B') return 0;
    }
    for(int i=y-s+1;i<y;i++){
        if(a[x-s][i]!='R') return 0;
        if(a[x+s-1][i]!='Y') return 0;
    }
    for(int i=y;i<y+s-1;i++){
        if(a[x-s][i]!='G') return 0;
        if(a[x+s-1][i]!='B') return 0;
    }
    return 1;
}
void init(){
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            for(int k=1;k<251;k++){
                if(!check(i,j,k)) break;
                d[k][i][j]=1;
            }
        }
    }
    for(int k=1;k<251;k++){
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                d[k][i][j]+=d[k][i][j-1];
            }
        }
        for(int j=1;j<m;j++){
            for(int i=1;i<n;i++){
                d[k][i][j]+=d[k][i-1][j];
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    init();
    for(int i=0;i<q;i++){
        int r1, c1, r2, c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        r1--;
        c1--;
        r2--;
        c2--;
        int j;
        for(j=250;j>0;j--){
            if(r2-(j-1)<0||c2-(j-1)<0||r1+(j-1)>=n||c1+(j-1)>=m) continue;
            if(r2-(j-1)<=r1+(j-1)||c2-(j-1)<=c1+(j-1)) continue;
            if(d[j][r2-(j-1)][c2-(j-1)]-d[j][r1+(j-1)][c2-(j-1)]-d[j][r2-(j-1)][c1+(j-1)]+d[j][r1+(j-1)][c1+(j-1)]>0){
                break;
            }
        }
        printf("%d\n",j*j*4);
    }
}