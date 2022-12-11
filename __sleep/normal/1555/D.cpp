#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int d[6][N],t,n,q;
char s[N],l[6][4]={"abc","acb","bca","bac","cab","cba"};
int main(){
    // scanf("%d",&t);
    t=1;
    while(t--){
        scanf("%d%d%s",&n,&q,s);
        for(int i=0;i<6;i++){
            for(int j=0;j<n;j++){
                if(s[j]==l[i][j%3]) d[i][j+1]++;
                d[i][j+1]+=d[i][j];
            }
        }
        int l,r,ans;
        while(q--){
            scanf("%d%d",&l,&r);
            ans=0;
            for(int i=0;i<6;i++)
                ans=max(ans,d[i][r]-d[i][l-1]);
            // printf("%d\n",d[5][r]-d[5][l-1]);
            printf("%d\n",r-l+1-ans);
        }
    }
    return 0;
}