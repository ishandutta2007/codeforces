#include<cstdio>
const int N=100005;
int n,m,t;
long long s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            long long x,y=0,z=0;
            for(int j=0;j<m;j++){
                scanf("%lld",&x);
                y+=x;
                z+=y;
            }
            s[i]=z;
        }
        int idx=-1,f=1;
        for(int i=2;i<=n;i++){
            if(s[i]>s[1]){idx=1; break;}
            if(s[i]<s[1]){idx=i; break;}
        }
        if(idx==1) f=2;
        printf("%d %lld\n",idx,s[f]-s[idx]);
    }
    return 0;
}