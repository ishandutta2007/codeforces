#include<cstdio>
#include<algorithm>
#include<vector>
#define pll pair<long long, long long>
using namespace std;
long long Comb[62][62], A[32][32], B[32][32], TT;
int R, C, n;
char p[110];
long long CC[32][32], MM;
vector< pll >P[32][2], Q[32][2];
void Put(int x, int y, long long g, long long c1, long long c2, int ck){
    if(x+y == R+n){
        P[x][ck].push_back({g,c1});
        if(c2)Q[x][ck].push_back({g,c2});
        
        return;
    }
    Put(x+1, y, g+(!ck?A[x+1][y]:0), c1, (p[x+y] != 'B' ? c2 : 0), ck);
    Put(x, y+1, g+(ck?B[x][y+1]:0), c1, (p[x+y] != 'A' ? c2 : 0), ck);
}
void Calc1(int x, int y, long long g, int ck){
    if(x+y == R+n){
        if(P[x][ck].empty())return;
        int t = lower_bound(P[x][ck].begin(),P[x][ck].end(), pll((TT+1)/2-g,0)) - P[x][ck].begin();
        if(t != P[x][ck].size() && P[x][ck][t].second > 0){
            long long tp = (P[x][ck][t].first + g) * 2 - TT;
            if(tp<0)tp=-tp;
            if(MM > tp)MM = tp;
        }
        if(t && P[x][ck][t-1].second > 0){
            long long tp = (P[x][ck][t-1].first + g) * 2 - TT;
            if(tp<0)tp=-tp;
            if(MM > tp)MM = tp;
        }
        return;
    }
    Calc1(x-1, y, g+(!ck?A[x][y]:0), ck);
    Calc1(x, y-1, g+(ck?B[x][y]:0), ck);
}

long long Res;

void Calc2(int x, int y, long long g, int ck){
    if(x+y == R+n){
        int t = lower_bound(Q[x][ck].begin(),Q[x][ck].end(), pll((TT+1)/2-g,0)) - Q[x][ck].begin();
        if(t != Q[x][ck].size() && Q[x][ck][t].second > 0){
            long long tp = (Q[x][ck][t].first + g) * 2 - TT;
            if(tp<0)tp=-tp;
            if(MM == tp){
                Res += Q[x][ck][t].second;
            }
        }
        if(t && Q[x][ck][t-1].second > 0){
            long long tp = (Q[x][ck][t-1].first + g) * 2 - TT;
            if(tp<0)tp=-tp;
            if(MM == tp){
                Res += Q[x][ck][t-1].second;
            }
        }
        return;
    }
    if(p[x+y-1] != 'B')Calc2(x-1, y, g+(!ck?A[x][y]:0), ck);
    if(p[x+y-1] != 'A')Calc2(x, y-1, g+(ck?B[x][y]:0), ck);
}

void Make(vector< pll > &P){
    if(P.empty())return;
    sort(P.begin(),P.end());
    int i, cnt = 0;
    long long s = 0;
    for(i=0;i<P.size();i++){
        s += P[i].second;
        if(i==P.size()-1 || P[i].first != P[i+1].first){
            P[cnt++] = {P[i].first, s};
            s = 0;
        }
    }
    P.resize(cnt);
}

int main(){
    int i, j;
    scanf("%d%d",&R,&C);
    scanf("%s",p);
    for(i=0;i<=60;i++){
        Comb[i][0]=1;
        for(j=1;j<=i;j++)Comb[i][j]=Comb[i-1][j-1]+Comb[i-1][j];
    }
    n = (R+C);
    TT = Comb[n*2][R*2];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i){
                if(i) A[i][j] = Comb[i-1][R-1] * (Comb[n*2-i][R] - Comb[j][R]);
            }
            if(j){
                if(j) B[i][j] = Comb[j-1][R-1] * (Comb[n*2-j][R] - Comb[i][R]);
            }
        }
    }
    CC[0][0]=1;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i!=n&&p[i+j] != 'B') CC[i+1][j] += CC[i][j];
            if(j!=n&&p[i+j] != 'A') CC[i][j+1] += CC[i][j];
        }
    }
    for(i=R;i<=n;i++){
        if(p[i+R-1]!='B')Put(R,i,A[R][i],Comb[i+R-1][R-1], CC[R-1][i],0);
        if(p[i+R-1]!='A')Put(i,R,B[i][R],Comb[i+R-1][R-1], CC[i][R-1],1);
    }
    for(i=R;i<=n;i++){
        for(j=0;j<2;j++){
            Make(P[i][j]);
            Make(Q[i][j]);
        }
    }
    MM = TT+1;
    Calc1(n, n, 0, 0);
    Calc1(n, n, 0, 1);
    Calc2(n, n, 0, 0);
    Calc2(n, n, 0, 1);
    printf("%lld\n",Res);
}