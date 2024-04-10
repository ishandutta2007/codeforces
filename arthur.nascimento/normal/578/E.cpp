#include <iostream>
#include <iomanip>
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
 
#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
  
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
#define pb push_back    
#define maxn 1001000			
#define mod 1000000007
 
using namespace std;

char v[maxn];

vector<int> ans[maxn];
char last[maxn];

int conta = 0;
int laste = -1;
int sz = 0;
int n;
void print(string,int t){
    printf("%d ",t);
    if(t < laste) conta++;
    if(laste+1) assert(v[laste-1] != v[t-1]);
    assert(t >= 1 && t <= n);
    sz++;
    
    laste = t;
}

void quit(int u){
       assert(conta == u);
       assert(sz == n);
       exit(0);
}

main(){
    
        scanf(" %s",v);
        
         n = strlen(v);
        
        set<int> A,B;
        int len = 0;
        
        vector<int> sa,sb;
        
        int la=0, lb=0;
        
        for(int i=0;i<n;i++){
            
            if(v[i] == 'L'){
                if(B.size() == 0){
                    ans[len].pb(i);
                    A.insert(len);
                    sa.pb(len);
                    len++;
                    la++;
                }
                else {
                    int u = *(B.begin());
                    B.erase(u);
                    ans[u].pb(i); debug("! %d\n",u);
                    A.insert(u);
                }
            }
            else {
                if(A.size() == 0){
                    ans[len].pb(i);
                    B.insert(len);
                    sb.pb(len);
                    len++;
                    lb++;
                 }
                 else {
                    int u = *(A.begin());
                    A.erase(u);
                    ans[u].pb(i); debug("@ %d\n",u);
                    B.insert(u);
                 }
            }
            
            }
            
            debug("la %d lb %d\n",la,lb);
            
            vector<vector<int> > ll, lr, rr, rl;
            
            printf("%d\n",len-1);
            
            for(int i=0;i<len;i++){
                char A = v[ans[i][0]];
                char B = v[ans[i][ans[i].size()-1]];
                debug("+ ");
                for(vector<int> :: iterator it = ans[i].begin(); it < ans[i].end(); it++) debug("%d ",1+*it);
                debug("\n");
                if(A == 'L' && B == 'L') { vector<int> aux; for(vector<int> :: iterator it = ans[i].begin(); it < ans[i].end(); it++) aux.pb(*it); ll.pb(aux); }
                if(A == 'L' && B == 'R') { vector<int> aux; for(vector<int> :: iterator it = ans[i].begin(); it < ans[i].end(); it++) aux.pb(*it); lr.pb(aux); }
                if(A == 'R' && B == 'L') { vector<int> aux; for(vector<int> :: iterator it = ans[i].begin(); it < ans[i].end(); it++) aux.pb(*it); rl.pb(aux); }
                if(A == 'R' && B == 'R') { vector<int> aux; for(vector<int> :: iterator it = ans[i].begin(); it < ans[i].end(); it++) aux.pb(*it); rr.pb(aux); }
            }
            
            debug("ll %d lr %d rl %d rr %d\n",(int)ll.size(),(int)lr.size(),(int)rl.size(),(int)rr.size());
            
            if(ll.size() && rr.size()){
                int y = min(ll.size(),rr.size());
                vector<int> novo;
                for(int k=0;k<y;k++){
                    for(vector<int> :: iterator it = rr[rr.size()-1].begin(); it < rr[rr.size()-1].end(); it++)
                        novo.pb(*it);
                    for(vector<int> :: iterator it = ll[ll.size()-1].begin(); it < ll[ll.size()-1].end(); it++)
                        novo.pb(*it);   
                    rr.pop_back();
                    ll.pop_back();
               }
               rl.pb(novo);
           }
           
           if(lr.size() > 1){
                vector<int> novo;
                while(lr.size()){
                    for(vector<int> :: iterator it = lr[lr.size()-1].begin(); it < lr[lr.size()-1].end(); it++) novo.pb(*it);
                    lr.pop_back();
                }
                lr.pb(novo);
           }
           
           if(rl.size() > 1){
                vector<int> novo;
                while(rl.size()){
                    for(vector<int> :: iterator it = rl[rl.size()-1].begin(); it < rl[rl.size()-1].end(); it++) novo.pb(*it);
                    rl.pop_back();
                }
                rl.pb(novo);
           }
           
           if(rr.size()){
                if(rl.size())
                    for(vector<int> :: iterator it = rl[0].begin(); it < rl[0].end(); it++) print("%d ",*it+1);
                for(vector<int> :: iterator it = rr[0].begin(); it < rr[0].end(); it++) print("%d ",*it+1);
                if(lr.size())
                    for(vector<int> :: iterator it = lr[0].begin(); it < lr[0].end(); it++) print("%d ",*it+1);
                printf("\n");
                quit(len-1);
           }
           
           if(ll.size()){
                if(lr.size())
                    for(vector<int> :: iterator it = lr[0].begin(); it < lr[0].end(); it++) print("%d ",*it+1);
                for(vector<int> :: iterator it = ll[0].begin(); it < ll[0].end(); it++) print("%d ",*it+1);
                if(rl.size())
                    for(vector<int> :: iterator it = rl[0].begin(); it < rl[0].end(); it++) print("%d ",*it+1);
                printf("\n");
                quit(len-1);
           }
           
           if(rl.size() == 0 || lr.size() == 0){
                 if(lr.size())
                    for(vector<int> :: iterator it = lr[0].begin(); it < lr[0].end(); it++) print("%d ",*it+1);
                 if(rl.size())
                    for(vector<int> :: iterator it = rl[0].begin(); it < rl[0].end(); it++) print("%d ",*it+1);
                 printf("\n");
                 quit(len-1);
           }
           
           vector<int> LR, RL;
           for(vector<int> :: iterator it = lr[0].begin(); it < lr[0].end(); it++) LR.pb(*it);
           for(vector<int> :: iterator it = rl[0].begin(); it < rl[0].end(); it++) RL.pb(*it);
           
           if(LR[LR.size()-1] > RL[RL.size()-1]){
                for(int i=0;i<LR.size()-1;i++)
                    print("%d ",1+LR[i]);
                for(int i=0;i<RL.size();i++)
                    print("%d ",1+RL[i]);
                print("%d\n",1+LR[LR.size()-1]);
                quit(len-1);
           }
           else {
                for(int i=0;i<RL.size()-1;i++)
                    print("%d ",1+RL[i]);
                for(int i=0;i<LR.size();i++)
                    print("%d ",1+LR[i]);
                print("%d\n",1+RL[RL.size()-1]);
                quit(len-1);
           }
           quit(len-1);
}