#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;

int v[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    int ans = 0;
    
    for(int i=-1;i<n;i++){
        
        map<int,int> foi;
        int bad = 0;
        for(int j=0;j<=i;j++){
            if(foi[v[j]]) bad = 1;
            foi[v[j]] = 1;
        }
        
        if(bad) continue;
        
        int cur = i+1;
        int u = n-1;
        while(!foi[v[u]] && u >=0){
            foi[v[u]] = 1;
            cur++;
            u--;
        }
        ans = max(ans,cur);
    }
    printf("%d\n",n-ans);
    
}