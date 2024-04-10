#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;

int pat[4][4] = {
8, 9 ,1, 13,
3 ,12, 7, 5,
0 ,2, 4, 11,
6 ,10 ,15, 14
};

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            int sub = (i/4) * (n/4) + (j/4);
            
            printf("%d ",16*sub + pat[i%4][j%4]);
            
            
        }
        printf("\n");
    }
    
}