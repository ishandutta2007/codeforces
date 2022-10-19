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

char a[maxn];
char b[maxn];
char c[maxn];

int main() {
    int nt;
    scanf("%d",&nt);
    while(nt--){
        
        scanf(" %s %s %s",a,b,c);
        int n = strlen(a);
        int ok = 1;
        for(int i=0;i<n;i++){
            
            if(a[i] == c[i] || b[i] == c[i]);
            else ok = 0;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
        
    }
}