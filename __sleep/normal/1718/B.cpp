#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=105;
int cnt=2,n,t;
long long fib[N],s[N];
int main(){
    fib[0]=fib[1]=1;
    s[0]=1; s[1]=2;
    do{
        fib[cnt]=fib[cnt-1]+fib[cnt-2];
        s[cnt]=s[cnt-1]+fib[cnt];
    } while(fib[cnt++]<=1e9);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        long long sum=0;
        priority_queue<int> a;
        for(int i=0,aa;i<n;i++){
            scanf("%d",&aa);
            sum+=aa;
            a.push(aa);
        }
        int len=lower_bound(s,s+cnt,sum)-s;
        int lst=0;
        if(s[len]!=sum) goto NO;
        do{
            if(a.empty()) goto NO;
            int now=a.top(); a.pop();
            if(now<fib[len]) goto NO;
            now-=fib[len];
            if(lst) a.push(lst);
            lst=now;
        }while(len--);
        puts("YES"); continue;
NO:     puts("NO");
    }
    return 0;
}