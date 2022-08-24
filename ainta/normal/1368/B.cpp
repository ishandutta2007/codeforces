#include<cstdio>
#include<algorithm>
using namespace std;
char pp[11]="codeforces";
int main(){
    int i, j;
    long long K;
    scanf("%lld",&K);
    for(i=10;;i++){
        long long z=1;
        for(j=0;j<10;j++){
            int t = i/10;
            if(j<i%10)t++;
            z*=t;
        }
        if(z>=K){
            for(j=0;j<10;j++){

                int t = i/10;
                if(j<i%10)t++;
                for(int k=0;k<t;k++)printf("%c",pp[j]);
            }
            puts("");
            return 0;
        }
    }
}