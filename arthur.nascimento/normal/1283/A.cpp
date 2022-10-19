#include <bits/stdc++.h>
#define maxn 400400
#define pb insert
#define ll long long
#define debug 
#define pii pair<int,int>
using namespace std;
 

int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int a,b;
        scanf("%d%d",&a,&b);
        int ans = 60-b + 60 * (23-a);
        printf("%d\n",ans);
    }
}