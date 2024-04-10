#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int c[200000],a[200000],v[200000],s[200000],idx=1;
vector<int> cur;
int main(){
    int N,i,ans=0,QQQ;
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&c[i]);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    for(i=0;i<N;i++){
        v[i]=0;
        s[i]=0;
    }
    for(i=0;i<N;i++){
        if(s[i]==0){
            int tmp=i;
            while(s[tmp]==0){
                s[tmp]=idx;
                tmp=a[tmp];
            }
            if(s[tmp]!=idx){
                idx++;
                continue;
            }
            QQQ=c[tmp];
            int tmp2=a[tmp];
            while(tmp2!=tmp){
                QQQ=min(QQQ,c[tmp2]);
                tmp2=a[tmp2];
            }
            ans+=QQQ;
            idx++;
        }
    }
    printf("%d\n",ans);
}