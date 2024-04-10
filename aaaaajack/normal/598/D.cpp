#include<cstdio>
#define N 1010
using namespace std;
bool v[N][N],f[N][N];
char s[N][N];
int val[N][N];
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
int n,m;
int count(int x,int y){
    v[x][y]=true;
    int ans=0;
    for(int i=0;i<4;i++){
        int tx=x+mx[i],ty=y+my[i];
        if(tx>=0 && tx<n && ty>=0 && ty<m){
            if(s[tx][ty]!='*'){
                if(!v[tx][ty]) ans+=count(tx,ty);
            }
            else ans++;
        }
    }
    return ans;
}
void fill(int x,int y,int c){
    f[x][y]=true;
    val[x][y]=c;
    for(int i=0;i<4;i++){
        int tx=x+mx[i],ty=y+my[i];
        if(tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty]!='*' && !f[tx][ty]){
            fill(tx,ty,c);
        }
    }
}
int main(){
    int k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!='*'&&!v[i][j]){
                int tmp=count(i,j);
                fill(i,j,tmp);
            }
        }
    }
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",val[x-1][y-1]);
    }
    return 0;
}