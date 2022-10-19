#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;
int v[maxn];
int A[550][550];
int B[550][550];

void go(int n,int m){
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(A[i][j] == 1){
                A[i][j]^=1;
                A[i+1][j]^=1;
                A[i][j+1]^=1;
                A[i+1][j+1]^=1;
            }
        }
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(B[i][j] == 1){
                B[i][j]^=1;
                B[i+1][j]^=1;
                B[i][j+1]^=1;
                B[i+1][j+1]^=1;
            }
        }
    }
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&A[i][j]);
             for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&B[i][j]);
        go(n,m);
    
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(A[i][j] != B[i][j]){
                        printf("No\n");
                        return 0;
                }
        printf("Yes\n");
}