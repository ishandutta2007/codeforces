#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<bitset>
#include<functional>
#include<time.h>
#include<assert.h>
#include<math.h>
#include<queue>
#include<memory.h>
#include<malloc.h>
 
using namespace std;
 
#define SZ 100005
 
char D[SZ];
int N;
 
int main(){
    int i, j;
    
    scanf("%s",D+1);
    N = strlen(D+1);
    
    for(i = 1; i <= N; i++){
        if(D[i] == '0') break;
    }
    
    if(i > N) i = N;
    for(j = 1; j <= N; j++){
        if(i != j) putchar(D[j]);
    }
    return 0;
}