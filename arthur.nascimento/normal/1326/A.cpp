#include <bits/stdc++.h>
#define maxn 4004000
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 998244353  
#define debug(args...) //printf(args)
using namespace std;
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MAXN 4004000
main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        int n;
        scanf("%d",&n);
        if(n == 1){
            printf("-1\n");
            continue;
        }
        int m3 = 0, p = 2;
        for(int i=0;i<n-1;i++){
            p = (10*p)%3;
            m3 = (m3+p) % 3;
        }
        if(m3 == 0){
            for(int i=0;i<n-2;i++) printf("2");printf("33\n");
        }
        else{
            for(int i=0;i<n-1;i++) printf("2"); printf("3\n");
        }
    }
}