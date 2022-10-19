#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug printf
using namespace std;
 

int pr(int n,int dif=0){
    for(int i=2;i*i<=n;i++)
        if(n%i == 0 && i != dif) return i;
    return n;

}

int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        
        int n;
        scanf("%d",&n);
        
        int a = pr(n);
        if(a == n){
            printf("NO\n"); continue;
        }
        int b = pr(n/a,a);
        if(a*b == n){
            printf("NO\n"); continue;
        }
        int c = n / (a*b);
        if(a == c || b == c){
            printf("NO\n"); continue;
        }
        printf("YES\n%d %d %d\n",a,b,n/(a*b));
        
    }
}