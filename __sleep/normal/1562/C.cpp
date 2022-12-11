#include<cstdio>
const int N=200005;
int t,n;
char s[200005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s+1);
        bool flag=0; int mid=n/2,z;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                z=i; flag=1;
                break;
            }
        }
        if(flag){
            if(z<=mid) printf("%d %d %d %d\n",z,n,z+1,n);
            else printf("%d %d %d %d\n",1,z,1,z-1);
        }
        else{
            printf("%d %d %d %d\n",1,n-1,2,n);
        }
    }
    return 0;
}