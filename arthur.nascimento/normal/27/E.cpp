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

#define eps 1e-9



#ifdef ONLINE_JUDGE

#define debug(args...)

#else

#define debug(args...) fprintf(stdout,args)

#endif



using namespace std;



int primos[15];

int P[8] = {2,3,5,7,11,13,17,19};

int v[15];

int qnt = 0;

long long ans = 1LL << 62;



long long exp2(long long a,int b){


    
        
    if(b == 0)
        return 1;

    if(b == 1)

        return a;



    long long ret = exp2(a,b/2);
    if(ret > 1000000000)
        return 1000000000000000000LL;
    ret *= ret;



    if(b%2)

        ret *= a;



    return ret;



}



void gera(int pos,int at,long long val,int last,int primo,string S = ""){



    if(val > 1000000000000000000LL)
        return;

    debug("%d %d %d %d %d\n",pos,at,val,last,primo);

    if(pos == qnt){

        if(exp2(P[primo],at-1) <= 1000000000000000000LL / val)

        ans = min(ans,val*exp2(P[primo],at-1));
        
        if(ans == 2)debug("!!\n");

        return;

    }



    if(at > last)

        return;



    gera(pos+1,at*primos[v[pos]],val,last,primo,S + " ");

    if(at != 1)

    gera(pos,1,val*exp2(P[primo],at-1),at,primo+1,S + " ");



}



main(){



    int n;

    scanf("%d",&n);

    

   



   for(int i=2;n!=1;i++){



    while(n%i == 0){ 

        primos[qnt++] = i;

        n /= i;

        }       

        }



    for(int i=0;i<qnt;i++)

        v[i] = i;



    do {



    debug("-> ");

    for(int i=0;i<qnt;i++)

        debug("%d ",primos[v[i]]);

    debug("\n");

    gera(0,1,1,99,0);

    debug("\n\n");

        }



        while(next_permutation(v,v+qnt));



    cout << ans << endl;

}