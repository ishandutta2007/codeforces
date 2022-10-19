#include <bits/stdc++.h>
#define maxn 404
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define debug
#define mk make_pair
#define pii pair<int,int>
using namespace std;

char ch(int id){
    if(id < 10) return id + '0';
    id -= 10;
    if(id < 26) return id + 'a';
    id -= 26;
    return id + 'A';
}

char M[maxn][maxn];
char ans[maxn][maxn];

int need[maxn];

main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int s = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf(" %c",&M[i][j]);
                s += (M[i][j] == 'R');   
            }
        for(int i=0;i<k;i++) need[i] =0 ;
        for(int i=0;i<s;i++) need[i%k]++;
        int u = s / k;
        int cur = 0, qtd = 0, dir = 1;
        for(int i=0;i<n;i++){
            
            int j = 0;
            if(dir == -1) j = m-1;
            while(j >= 0 && j < m){
                ans[i][j] = ch(cur);
                if(M[i][j] == 'R') qtd++;
                if(qtd == need[cur] && cur != k-1){
                    cur++;
                    qtd = 0;
                }
                
                j += dir;
            }
            dir = -dir;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
        
    }
    
}