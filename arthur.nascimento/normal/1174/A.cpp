#include <bits/stdc++.h>
#define pb push_back
using namespace std;

#define maxn 400400

vector<int> L[maxn];
int v[maxn];
int main() {
    int n;
    scanf("%d",&n);
    
    int ans = 0;
    for(int i=0;i<2*n;i++){
        scanf("%d",v+i);
        if(v[i] != v[0])
            ans = 1;
    }
    sort(v,v+2*n);
    if(ans == 0) printf("-1\n");
    else{
        for(int i=0;i<2*n;i++)
            printf("%d ",v[i]);
    }
}