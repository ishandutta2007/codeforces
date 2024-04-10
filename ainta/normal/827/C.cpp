#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define SZ 131072
class Tree{
public:
    vector<int>BIT;
    int n;
    void init(int a){
        n = a;
        BIT.resize(a+1);
    }
    void Ins(int a, int b){
        while(a<=n){
            BIT[a] += b;
            a+=(a&-a);
        }
    }
    int Sum(int a){
        int r = 0;
        while(a){
            r+=BIT[a];
            a-=(a&-a);
        }
        return r;
    }
}T[11][11][4];
char p[101000], q[110];
int L, CC[220], Q;
void Put(int a, int num){
    int j;
    for(j=1;j<=10;j++){
        T[j][a%j][num].Ins(a/j+1, 1);
    }
}
void Del(int a, int num){
    int j;
    for(j=1;j<=10;j++){
        T[j][a%j][num].Ins(a/j+1, -1);
    }
}
int main(){
    int i, j, k, ck, a, b;
    scanf("%s",p);
    for(i=0;p[i];i++);
    L = i;
    CC['A'] = 0;
    CC['C'] = 1;
    CC['G'] = 2;
    CC['T'] = 3;
    for(i=1;i<=10;i++){
        for(j=0;j<i;j++){
            for(k=0;k<4;k++){
                T[i][j][k].init(L/i+1);
            }
        }
    }
    for(i=0;i<L;i++){
        Put(i, CC[p[i]]);
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&ck,&a);
        if(ck==1){
            a--;
            scanf("%s",q);
            Del(a, CC[p[a]]);
            p[a] = q[0];
            Put(a, CC[p[a]]);
            continue;
        }
        scanf("%d%s",&b,q);
        a--,b--;
        for(i=0;q[i];i++);
        int l = i, res = 0;
        for(i=0;i<l;i++){
            int mm = (i+a)%l;
            int bb = a/l+1, ee = b/l+1;
            if(b%l < mm) ee--;
            if(a%l > mm) bb++;
            res += T[l][mm][CC[q[i]]].Sum(ee) - T[l][mm][CC[q[i]]].Sum(bb-1);
        }
        printf("%d\n",res);
    }
}