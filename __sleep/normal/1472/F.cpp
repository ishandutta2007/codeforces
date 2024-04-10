#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int t,n,m,flag,ans;
struct P{
    int r,c;
}p[N];
inline bool cmp(const P a,const P b){
    if(a.c==b.c) return a.r<b.r;
    return a.c<b.c;
}
int main(){
    int rr,cc;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&rr,&cc);
            p[i].r=rr;
            p[i].c=cc;
        }
        std::sort(p,p+m,cmp);
        flag=ans=1;
        if(m&1){
            puts("NO");
            continue;
        }
        for(int i=1;i<m;i++){
            if(!flag){ 
                if(p[i].c==p[i-1].c){
                    ans=0;
                    break;
                }
                flag^=1;
                continue;
            }
            if(p[i].r!=p[i-1].r){
                if((p[i].c-p[i-1].c)&1){
                    ans=0; break;
                }
            }
            else if(!((p[i].c-p[i-1].c)&1)){
                ans=0; break;
            }
            flag^=1;
        }
        puts(ans?"YES":"NO");
    }
    return 0;
}