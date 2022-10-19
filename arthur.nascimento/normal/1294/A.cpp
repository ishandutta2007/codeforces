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
        
        int n,v[3];
        scanf("%d%d%d%d",v,v+1,v+2,&n);
        sort(v,v+3);
        n -= v[2]-v[1];
        v[1] += v[2]-v[1];
        n -= v[1]-v[0];
        v[0] += v[1]-v[0];
        if(n < 0 || n%3 != 0)
            printf("NO\n");
        else
            printf("YES\n");
        
    }
}