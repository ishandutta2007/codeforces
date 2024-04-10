#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
vector<int>BIT[1010000], E[1010000];
int Q, n, cnt;
struct A{
    int ck, a, t;
}w[1010000];
map<int,int>Map;
void Ins(int a, int b, int c){
    int sz = E[a].size()-1;
    while(b<=sz){
        BIT[a][b]+=c;
        b+=(b&-b);
    }
}
int Sum(int a, int b){
    int r = 0;
    while(b){
        r += BIT[a][b];
        b-=(b&-b);
    }
    return r;
}
int Find(int a, int t){
    int b = 1, e = E[a].size()-1, mid;
    while(b<=e){
        mid = (b+e)>>1;
        if(E[a][mid] == t)return mid;
        if(E[a][mid] < t){
            b = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
}
int main(){
    int i,x;
    scanf("%d",&Q);
    for(i=1;i<=Q;i++){
        scanf("%d%d%d",&w[i].ck,&w[i].t,&x);
        if(!Map[x])Map[x] = ++cnt;
        w[i].a = Map[x];
        E[w[i].a].push_back(w[i].t);
    }
    for(i=1;i<=cnt;i++){
        E[i].push_back(-1);
        sort(E[i].begin(),E[i].end());
        BIT[i].resize(E[i].size());
    }
    for(i=1;i<=Q;i++){
        x = Find(w[i].a,w[i].t);
        if(w[i].ck == 1){
            Ins(w[i].a,x, 1);
        }
        if(w[i].ck == 2){
            Ins(w[i].a, x, -1);
        }
        if(w[i].ck == 3){
            printf("%d\n",Sum(w[i].a, x));
        }
    }
}