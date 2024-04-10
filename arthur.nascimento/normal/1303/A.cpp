#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) printf(args)
using namespace std;

char s[maxn];

main(){
    
    int nt;
    scanf("%d",&nt);
    while(nt--){
        scanf(" %s",s);
        int n = strlen(s);
        int q1 = 0, f1 = n+1, l1 = -1;
        for(int i=0;i<n;i++)
            if(s[i] == '1'){
                q1++;
                f1 = min(f1,i);
                l1 = i;
            }
            
        if(q1 == 0)
            printf("0\n");
        else
            printf("%d\n",l1-f1+1-q1);
    }
}