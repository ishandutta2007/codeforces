#include<stdio.h>
#include<algorithm>
using namespace std;
char p[101000];
int w[101000], n, st[101000], Nxt[101000], Res;
bool v[101000];
int P[4][101000], cnt[4];
void Make_Link(){
    int i, t;
    for(i=1;i<=n;i++)v[i]=false;
    for(i=1;i<=n;i++)v[Nxt[i]]=true;
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    for(i=1;i<=n;i++){
        if(!v[i]){
            t = i;
            while(Nxt[t])t=Nxt[t];
            if(w[i]==0&&w[t]==1)P[0][cnt[0]++] = i;
            if(w[i]==1&&w[t]==0)P[1][cnt[1]++] = i;
            if(w[i]==0&&w[t]==0)P[2][cnt[2]++] = i;
            if(w[i]==1&&w[t]==1)P[3][cnt[3]++] = i;
        }
    }
}
void Do(int a){
    cnt[a]--;
    int x = P[a][cnt[a]];
    while(x){
        printf("%d ",x);
        x=Nxt[x];
    }
}
int main(){
    int i, t, t2;
    scanf("%s",p);
    for(i=0;p[i];i++){
        w[i+1] = (p[i]=='L'?0:1);
    }
    n = i;
    int top = 0;
    Res = n-1;
    for(i=1;i<=n;i++){
        if(w[i]==0)st[++top] = i;
        else{
            if(top){
                Nxt[st[top]] = i;
                top--;
                Res--;
            }
        }
    }
    top = 0;
    for(i=1;i<=n;i++){
        if(w[i]==1)st[++top] = i;
        else{
            if(top){
                Nxt[st[top]] = i;
                top--;
                Res--;
            }
        }
    }
    printf("%d\n",Res);
    Make_Link();
    if(cnt[0] && cnt[1] && !cnt[2]&& !cnt[3]){
        t = P[0][0], t2 = P[1][0];
        while(Nxt[t])t=Nxt[t];
        while(Nxt[t2])t2=Nxt[t2];
        if(t2<t)swap(t,t2);
        for(i=1;i<=n;i++)if(Nxt[i] == t2)Nxt[i]=0;
        Nxt[t] = t2;
        Make_Link();
    }
    if(!cnt[2] && !cnt[3]){
        if(cnt[0]){
            while(cnt[0])Do(0);
        }
        else{
            while(cnt[1])Do(1);
        }
    }
    else{
        if(cnt[2] + 1 == cnt[3]){
            while(cnt[1])Do(1);
            Do(3);
            while(cnt[0])Do(0);
            while(1){
                if(!cnt[2])break;
                Do(2);
                if(!cnt[3])break;
                Do(3);
            }
        }
        else{
            while(cnt[0])Do(0);
            Do(2);
            while(cnt[1])Do(1);
            while(1){
                if(!cnt[3])break;
                Do(3);
                if(!cnt[2])break;
                Do(2);
            }
        }
    }
}