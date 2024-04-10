#include <bits/stdc++.h>
#define maxn 400400
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007 
#define debug(args...) //printf(args)
using namespace std;

char s[maxn];

main(){
    scanf(" %s",s);
    int n = strlen(s);
    vector<int> ans;
    for(int i=0;i<n;i++){
        vector<int> aa;
        int ini = 0, fim = n-1;
        int aux = i;
        while(aux > 0 && ini < n){
            if(s[ini] == '('){
                aux--;
                aa.pb(ini);
            }
            ini++;
        }
        debug("aux %d\n",aux);
        if(aux > 0) break;
        aux = i;
        while(aux > 0 && fim >= 0){
            if(s[fim] == ')'){
                aux--;
                aa.pb(fim);
            }
            fim--;
        }
        debug("aux %d\n",aux);
        if(aux > 0) break;
        fim++;
        debug("i %d ini %d fim %d\n",i,ini,fim);
        if(ini > fim) break;
        ans = aa;
    }
    if(ans.size() == 0){
        printf("0\n");
        return 0;
    }
    sort(ans.begin(),ans.end());
    printf("1\n%d\n",ans.size());
    for(int i : ans)
        printf("%d ",i+1);
    printf("\n");
    
}