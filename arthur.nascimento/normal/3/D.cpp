#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int abre[100100];
int fecha[100100];
int p[100100];

int muda[100100];

int pos[100100];

char ans[100100];

main(){
       
       char ch;
       int n = 0;
       int qnt = 0;
       int sum = 0;
       long long resp = 0;
       
       while((ch=getchar()) != '\n'){
            
            if(ch == '(')
                sum++;
            if(ch == ')')
                sum--;
            if(ch == '?')
                sum--,
                pos[qnt++] = n;
                
            if(ch == '?')
                p[n] = 1;
                
            if(ch == '(')
                ans[n] = '(';
            else
                ans[n] = ')';
            
            muda[n] = max(0,-(sum-1)/2);
            debug("muda[%d] = %d\n",n,muda[n]);
            
            n++;
            
        }
        
        priority_queue<pii> Q;
        
        int mudou = 0;
        
        int j = 0;
        for(int i=0;i<n;i++){
            
            if(p[i]){
                scanf("%d%d",abre+j,fecha+j);
                resp += fecha[j];
            
                Q.push(pii(fecha[j]-abre[j], pos[j]));
                j++;       
            }
            
            while(mudou < muda[i]){
                if(Q.empty()){
                    printf("-1\n");
                    return 0;   
                }
                mudou++;
                sum += 2;
                pii k = Q.top();
                Q.pop();
                resp -= k.first;
                ans[k.second] = '(';
                debug("muda %d\n",k.second);
            }    
                    
        }
        
        if(mudou > muda[n-1] || sum != 0){
            printf("-1\n");
            return 0;
        }

        printf("%I64d\n",resp);
        for(int i=0;i<n;i++)
            printf("%c",ans[i]);
            
}