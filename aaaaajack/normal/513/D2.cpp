#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1001000
using namespace std;
int c[N][2][2];
vector<int> ans;
void upd(int a,int b,int l){
    if(!c[a][l][0]||b<c[a][l][0]){
        c[a][l][0]=b;
    }
    if(!c[a][l][1]||b>c[a][l][1]){
        c[a][l][1]=b;
    }
}
bool check(int rt,int ed,int &red){
    if(!c[rt][0][0]){
        ans.push_back(rt);
        if(rt==ed&&!c[rt][1][0]){
            red=ed;
            return true;
        }
        return check(rt+1,max(ed,c[rt][1][1]),red);
    }
    int tmp;
    if(!check(rt+1,c[rt][0][1],tmp)) return false;
    ans.push_back(rt);
    if(tmp>=ed&&!c[rt][1][0]){
        red=tmp;
        return true;
    }
    if(c[rt][1][0]&&tmp>=c[rt][1][0]) return false;
    return check(tmp+1,max(tmp+1,max(ed,c[rt][1][1])),red);
}
int main(){
    int n,m,a,b,i;
    bool flag=false;
    char s[10];
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%s",&a,&b,s);
        if(a>=b) flag=true;
        if(s[0]=='L') upd(a,b,0);
        else upd(a,b,1);
    }
    if(flag) puts("IMPOSSIBLE");
    else if(!check(1,n,i)||i>n) puts("IMPOSSIBLE");
    else{
        printf("%d",ans[0]);
        for(i=1;i<ans.size();i++) printf(" %d",ans[i]);
        putchar('\n');
    }
    return 0;
}