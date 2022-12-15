#include <bits/stdc++.h>
using namespace std;

int n,k,ps[510][510];
char str[510][510];

int getIdx(int y,int x) {
    y--;x--;
    return y*n+x;
}

int pa[250001],cnt[250001],chk[250001],rf[250001];
int find(int cur) {
    return cur==pa[cur] ? cur : pa[cur] = find(pa[cur]);
}
void merge(int u,int v) {
    u=find(u);v=find(v);
    if(u!=v) {
        pa[v]=u; cnt[u]+=cnt[v];
    }
}

const int dy[]={-1,1,0,0},dx[]={0,0,-1,1};
bool go(int y,int x) {
    return y>=0 && x>=0 && y<=n && x<=n && str[y][x]=='.';
}

inline int upd(int idx,int v,int br) {
    if(rf[idx]!=br) {
        rf[idx]=br; chk[idx]=0;
    }
    int ret=0;
    if(v==1) {
        if(chk[idx]==0) ret=cnt[idx];
    } else {
        if(chk[idx]==1) ret=-cnt[idx];
    }
    chk[idx]+=v;
    return ret;
}
int psum(int y1,int x1,int y2,int x2) {
    return ps[y2][x2] - ps[y1-1][x2] - ps[y2][x1-1] + ps[y1-1][x1-1];
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);

    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) 
        ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+(str[i][j]=='X');

    for(int i=0;i<n*n;i++) pa[i]=i,cnt[i]=(str[i/n+1][i%n+1]=='X' ? 0 : 1);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(str[i][j]=='.') {
        for(int k=0;k<4;k++) {
            int y=i+dy[k],x=j+dx[k];
            if(go(y,x)) merge(getIdx(i,j),getIdx(y,x));
        }
    }

    int ans=0;
    for(int r=1;r+k-1<=n;r++) {
        int s=0;
        for(int i=r;i<r+k;i++)for(int j=1;j<=k;j++) if(str[i][j]=='.') {
            int idx = find(getIdx(i,j));
            s+=upd(idx,1,r);
        }
        if(r!=1) for(int j=1;j<=k;j++) if(str[r-1][j]=='.') {
            int idx=find(getIdx(r-1,j));
            s+=upd(idx,1,r);
        }
        if(r+k<=n) for(int j=1;j<=k;j++) if(str[r+k][j]=='.') {
            int idx=find(getIdx(r+k,j));
            s+=upd(idx,1,r);
        }
        if(k!=n) for(int i=r;i<r+k;i++) if(str[i][k+1]=='.') {
            int idx=find(getIdx(i,k+1));
            s+=upd(idx,1,r);
        }

        ans = max(ans, s + psum(r,1,r+k-1,k));
        for(int j=2;j+k-1<=n;j++) {
            if(j>2) {
                for(int i=r;i<r+k;i++) if(str[i][j-2]=='.') {
                    int idx=find(getIdx(i,j-2));
                    s+=upd(idx,-1,r);
                }
            }
            if(r!=1) {
                if(str[r-1][j-1]=='.') {
                    int idx=find(getIdx(r-1,j-1));
                    s+=upd(idx,-1,r);
                }
                if(str[r-1][j+k-1]=='.') {
                    int idx=find(getIdx(r-1,j+k-1));
                    s+=upd(idx,1,r);
                }
            }
            if(r+k<=n){
                if(str[r+k][j-1]=='.') {
                    int idx=find(getIdx(r+k,j-1));
                    s+=upd(idx,-1,r);
                }
                if(str[r+k][j+k-1]=='.') {
                    int idx=find(getIdx(r+k,j+k-1));
                    s+=upd(idx,1,r);
                }
            }
            if(j+k<=n) {
                for(int i=r;i<r+k;i++) if(str[i][j+k]=='.') {
                    int idx=find(getIdx(i,j+k));
                    s+=upd(idx,1,r);
                }
            }
            ans = max(ans, s+psum(r,j,r+k-1,j+k-1));
        }
    }
    printf("%d\n",ans);
    
    return 0;
}