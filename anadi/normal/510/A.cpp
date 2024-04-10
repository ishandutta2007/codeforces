#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<n;i+=2){
            for(int j=0;j<m;++j)
                    printf("#");
            puts("");
            if(i%4==1){
                       for(int j=1;j<m;++j)
                               printf(".");
                       printf("#");
            }
            else{
                 printf("#");
                 for(int j=1;j<m;++j)
                         printf(".");
            }
            puts("");
    }
    if(n%2==1){
               for(int i=0;i<m;++i)
                       printf("#");
    }
    return 0;
}