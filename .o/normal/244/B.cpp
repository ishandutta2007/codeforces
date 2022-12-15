#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<set>

using namespace std;

int res;
long long N;
set<int> ret;

int main(){
    int x, y;

    scanf("%d",&N);
    for(x = 0; x <= 9; x++) for(y = x; y <= 9; y++){
        if(!x && !y) continue;
        for(int l = 1; l <= 10; l ++){
            for(int s = 0; s < (1<<l); s++){
                long long v = 0; bool ck = false;
                for(int i = 0; i < l; i++){
                    v *= 10;
                    if(s & (1<<i)){
                        if(!ck && x == 0){ v = N + 1; break; }
                        v += x; if(x) ck = true;
                    }else{ 
                        if(!ck && y == 0){ v = N + 1; break; }
                        v += y; if(y) ck = true;
                    }
                }
            
                if(v > 0 && v <= N && ret.find(v) == ret.end()){
                    ++res; ret.insert(v);
                }
            }
        }
    }

    printf("%d\n",res);
    return 0;
}