#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int row[1000000][2], col[1000000][2];
int rf, cf, rimp, cimp;
int chess[2];
map<pair<int,int>, int> mp;
long long aaaa[1000001];
void init(){
    aaaa[0]=1;
    for(int i=1;i<1000001;i++) aaaa[i]=aaaa[i-1]*2%998244353;
}
void process(){
    int x,y,t;
    cin >> x >> y >> t;
    x--;y--;
    if(t==-1){
        if(mp.count({x,y})){
            int kk = mp[{x,y}];
            int ktmp = (y+kk)%2;
            row[x][ktmp]--;
            if(row[x][ktmp]==0){
                if(row[x][!ktmp]) rimp--;
                rf++;
            }
            ktmp = (x+kk)%2;
            col[y][ktmp]--;
            if(col[y][ktmp]==0){
                if(col[y][!ktmp]) cimp--;
                cf++;
            }
            chess[(kk+x+y)%2]--;
            mp.erase({x,y});
        }
    }
    else{
        if(mp.count({x,y})){
            int kk = mp[{x,y}];
            if(kk != t){
                int ktmp = (y+kk)%2;
                row[x][ktmp]--;
                if(row[x][ktmp]==0){
                    if(row[x][!ktmp]) rimp--;
                    rf++;
                }
                ktmp = (x+kk)%2;
                col[y][ktmp]--;
                if(col[y][ktmp]==0){
                    if(col[y][!ktmp]) cimp--;
                    cf++;
                }
                chess[(kk+x+y)%2]--;
                ktmp = (y+t)%2;
                row[x][ktmp]++;
                if(row[x][ktmp]==1){
                    if(row[x][!ktmp]) rimp++;
                    rf--;
                }
                ktmp = (x+t)%2;
                col[y][ktmp]++;
                if(col[y][ktmp]==1){
                    if(col[y][!ktmp]) cimp++;
                    cf--;
                }
                chess[(t+x+y)%2]++;
                mp[{x,y}] = t;
            }
        }
        else{
            int ktmp = (y+t)%2;
            row[x][ktmp]++;
            if(row[x][ktmp]==1){
                if(row[x][!ktmp]) rimp++;
                rf--;
            }
            ktmp = (x+t)%2;
            col[y][ktmp]++;
            if(col[y][ktmp]==1){
                if(col[y][!ktmp]) cimp++;
                cf--;
            }
            chess[(t+x+y)%2]++;
            mp[{x,y}] = t;
        }
    }
    cout << ((rimp?0:aaaa[rf])+(cimp?0:aaaa[cf])-(!chess[0])-(!chess[1])+998244353)%998244353 << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    init();
    cin >> n >> m >> k;
    rf = n; cf = m;
    for(int i=0;i<k;i++) process();
}