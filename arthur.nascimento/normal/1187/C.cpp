#include <bits/stdc++.h>
#define maxn 2020
#define pb push_back
#define pii pair<int,int>
#define debug 
using namespace std;
 
int ty[maxn];
int l[maxn];
int r[maxn];

int eq[maxn];
int v[maxn];
 
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",ty+i,l+i,r+i), l[i]--, r[i]--;
        if(ty[i])
            for(int j=l[i];j<r[i];j++)
                eq[j] = 1;
    }
    
    v[0] = n;
    for(int i=1;i<n;i++)
        v[i] = eq[i-1] ? v[i-1] : (v[i-1]-1);
    
    
    int ok = 1 ;
    
    for(int i=0;i<m;i++)
        if(ty[i] == 0){
            int h = 0;
            for(int j=l[i];j<r[i];j++)
                if(v[j] > v[j+1]) h = 1;
            if(h == 0) ok = 0;
        }
        
    if(ok == 0)
        printf("NO\n");
    else {
        printf("YES\n");
        for(int i=0;i<n;i++)
            printf("%d ",v[i]);
        printf("\n");
    }
}