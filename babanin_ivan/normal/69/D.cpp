#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define int64 long long       
#define ld long double

const int inf=2000000000;

int n,d;
int x[25],y[25];

int used[1000][1000];

inline bool dist(int x,int y){
    if (sqrt(ld(x-200)*ld(x-200)+ld(y-200)*ld(y-200))>=d)
        return true;
    else return false;
}

bool dfs(int tekx,int teky,bool used1,bool used2){
    if (used[tekx][teky]){
        if (used[tekx][teky]==1)
            return true;
        else return false;
    }
    if (dist(tekx,teky)){
        used[tekx][teky]=1;
        return true;
    }
    int kpr=0;
    bool tek;
    if (used1){
        tek=dfs(teky,tekx,used2,false);
        if (!tek)
            ++kpr;
    }
    for (int i=0;i<n;++i){
        tek=dfs(tekx+x[i],teky+y[i],used2,used1);
        if (!tek)
            ++kpr;
    }
    if (kpr){
        used[tekx][teky]=1;
        return true;
    }
    used[tekx][teky]=2;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int startx,starty;
    scanf("%d %d %d %d",&startx,&starty,&n,&d);
    startx+=200;
    starty+=200;
    for (int i=0;i<n;++i)
        scanf("%d %d",&x[i],&y[i]);
    bool ans=dfs(startx,starty,true,true);
    if (ans)
        cout<<"Anton\n";
    else cout<<"Dasha\n";
    return 0;
}