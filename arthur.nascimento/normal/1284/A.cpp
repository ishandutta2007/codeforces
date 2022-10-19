#include <bits/stdc++.h>
#define maxn 110
#define pb insert
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
 
char a[maxn][maxn];
char b[maxn][maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<m;i++)
        scanf(" %s",b[i]);
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        t--;
        printf("%s%s\n",a[t%n],b[t%m]);
        
    }
}