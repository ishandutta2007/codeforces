#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;

int T;
int n,m,tot;
char s[N][N];
pair<int,int> ans[N*N][3];

void work(int x,int y){
    static vector<pair<int,int>> a,b;
    a.clear();
    b.clear();
    for(int i=x;i<=x+1;++i)
    for(int j=y;j<=y+1;++j)
    if(s[i][j]){
        a.push_back({i,j});
    }
    else{
        b.push_back({i,j});
    }
    if(a.size()==4){
        ++tot;
        for(int i=0;i<3;++i)ans[tot][i]=a[i],s[a[i].first][a[i].second]^=1;
        a.clear();b.clear();
        for(int i=x;i<=x+1;++i)
        for(int j=y;j<=y+1;++j)
        if(s[i][j]){
            a.push_back({i,j});
        }
        else{
            b.push_back({i,j});
        }
    }
    if(a.size()==1){
        ++tot;
        ans[tot][2]=a[0];s[a[0].first][a[0].second]^=1;
        for(int i=0;i<2;++i)ans[tot][i]=b[i],s[b[i].first][b[i].second]^=1;
        a.clear();b.clear();
        for(int i=x;i<=x+1;++i)
        for(int j=y;j<=y+1;++j)
        if(s[i][j]){
            a.push_back({i,j});
        }
        else{
            b.push_back({i,j});
        }
    }
    if(a.size()==3){
        ++tot;
        for(int i=0;i<3;++i)ans[tot][i]=a[i];
    }
    if(a.size()==2){
        ++tot;
        for(int i=0;i<2;++i)ans[tot][i]=b[i];
        ans[tot][2]=a[0];
        ++tot;
        for(int i=0;i<2;++i)ans[tot][i]=b[i];
        ans[tot][2]=a[1];
    }
}


void Solve(int x,int y){
    static vector<int> a,b;
    a.clear();
    b.clear();
    if(s[x+1][y]){
        ++tot;
        ans[tot][0]={x,y};s[x][y]^=1;
        ans[tot][1]={x+1,y};s[x+1][y]^=1;
        ans[tot][2]={x,y+1};s[x][y+1]^=1;
    }
}

void Solve1(int x,int y){
    static vector<int> a,b;
    a.clear();
    b.clear();
    if(s[x+1][y+1]){
        ++tot;
        ans[tot][0]={x,y};s[x][y]^=1;
        ans[tot][1]={x,y+1};s[x][y+1]^=1;
        ans[tot][2]={x+1,y+1};s[x+1][y+1]^=1;
    }
}

void Solve2(int x,int y){
    static vector<int> a,b;
    a.clear();
    b.clear();
    if(s[x][y+1]){
        ++tot;
        ans[tot][1]={x,y+1};s[x][y+1]^=1;
        ans[tot][0]={x,y};s[x][y]^=1;
        ans[tot][2]={x+1,y+1};s[x+1][y+1]^=1;
    }
}


void Solve3(int x,int y){
    static vector<int> a,b;
    a.clear();
    b.clear();
    if(s[x+1][y+1]){
        ++tot;
        ans[tot][0]={x,y};s[x][y]^=1;
        ans[tot][1]={x+1,y};s[x+1][y]^=1;
        ans[tot][2]={x+1,y+1};s[x+1][y+1]^=1;
    }
}


int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
        tot=0;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            s[i][j]-='0';
        }
        if(n&1){
            for(int j=1;j<m;++j){
                Solve(n-1,j);
            }
            Solve1(n-1,m-1);
            n--;
        }
        if(m&1){
            for(int i=1;i<n;++i){
                Solve2(i,m-1);
            }
            Solve3(n-1,m-1);
            m--;
        }
        for(int i=1;i<n;i+=2)
        for(int j=1;j<m;j+=2){
            work(i,j);
        }
        cout<<tot<<endl;
        for(int i=1;i<=tot;++i){
            cout<<ans[i][0].first<<" "<<ans[i][0].second<<" "<<ans[i][1].first<<" "<<ans[i][1].second<<" "<<ans[i][2].first<<" "<<ans[i][2].second<<endl;
        }
    }
}