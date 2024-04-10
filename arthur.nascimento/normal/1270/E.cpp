#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
int x[maxn];
int y[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",x+i,y+i);
    while(1){
        
        int pp=0,ii=0;
        for(int i=0;i<n;i++){
            if((x[i]+y[i])%2 == 0) pp=1;
            else ii=1;
        }
        
        if(pp == ii){
            int sz = 0;
            for(int i=0;i<n;i++)
                if((x[i]+y[i]) % 2 == 0) sz++;
            printf("%d\n",sz);
            for(int i=0;i<n;i++)
                if((x[i]+y[i]) % 2 == 0) printf("%d ",i+1);
            printf("\n");
            return 0;
        }
        
        if(pp){
            for(int i=0;i<n;i++){
                int X = x[i], Y = y[i];
                x[i] = (X+Y)/2;
                y[i] = (X-Y)/2;
            }
        }
        else {
            for(int i=0;i<n;i++){
                int X = x[i]+1, Y = y[i];
                x[i] = (X+Y)/2;
                y[i] = (X-Y)/2;
                debug("%d: %d %d\n",i,x[i],y[i]);
            }
        }
        
    }
}