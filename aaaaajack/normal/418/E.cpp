#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define N 100010
#define S 170
using namespace std;
int a[N];
int num[2*N],cnt=0;
int odd[S][2*N]={0},evn[S][2*N]={0};
int main(){
    int i,j,n,m,sq,t,v,x,y,os;
    map<int,int> id;
    scanf("%d",&n);
    sq=(int)ceil(sqrt(n)*2);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(id.find(x)!=id.end()){
            a[i]=id[x];
        }
        else{
            a[i]=cnt;
            num[cnt]=x;
            id.insert(make_pair(x,cnt++));
        }
        for(j=i/sq+1;j<=n/sq;j++){
            x=++evn[j][a[i]];
            odd[j][x]++;
        }
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&t,&x,&y);
        if(t==1){
            if(id.find(x)!=id.end()){
                v=id[x];
            }
            else{
                v=cnt;
                num[cnt]=x;
                id.insert(make_pair(x,cnt++));
            }
            for(j=(y-1)/sq+1;j<=n/sq;j++){
                odd[j][evn[j][a[y-1]]--]--;
                odd[j][++evn[j][v]]++;
            }
            a[y-1]=v;
        }
        else{
            if(x==1) printf("%d\n",num[a[y-1]]);
            else if(x&1){
                os=sq*(y/sq);
                for(j=0;j<y%sq;j++){
                    odd[y/sq][++evn[y/sq][a[os+j]]]++;
                }
                printf("%d\n",odd[y/sq][evn[y/sq][a[y-1]]]);
                for(j=y%sq-1;j>=0;j--){
                    odd[y/sq][evn[y/sq][a[os+j]]--]--;
                }
            }
            else{
                os=sq*(y/sq);
                for(j=0;j<y%sq;j++){
                    evn[y/sq][a[os+j]]++;
                }
                printf("%d\n",evn[y/sq][a[y-1]]);
                for(j=y%sq-1;j>=0;j--){
                    evn[y/sq][a[os+j]]--;
                }
            }
        }
    }
    return 0;
}