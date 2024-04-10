#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<vector<int> > e;
int main(){
	AquA;
    int n,m;
    cin >> n >> m;
    e.resize(n,vector<int>(n,500));
    vector<vector<int> > v(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        e[a][b]=e[b][a]=1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        e[i][i]=0;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    const int mod=998244353;
    auto add=[](int& x,int y){
        x+=y;
        x-=mod*(x>=mod);
    };
    auto mul=[](int x,int y){
        return 1ll*x*y%mod;
    };
    vector<vector<int> > tmp(n,vector<int>(n)),ans(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(k==i || k==j){
                    continue;
                }
                if(e[i][k]+e[k][j]==e[i][j]){
                    cnt++;
                }
            }
            if(cnt>=e[i][j]){
                ans[i][j]=ans[j][i]=0;
                continue;
            }
            for(int k=0;k<n;k++){
                if(k==i || k==j){
                    continue;
                }
                cnt=0;
                if(e[i][k]+e[k][j]!=e[i][j]){
                    if((e[i][k]+e[k][j]-e[i][j])%2==1){
                        ans[i][j]=ans[j][i]=0;
                        break;
                    }
                    int a=(e[i][k]+e[k][j]-e[i][j])/2,b=e[i][k]-a;
                    for(auto h:v[k]){
                        int c=(e[i][h]+e[h][j]-e[i][j])/2,d=e[i][h]-c;
                        if(d==b && a==c+1){
                            cnt++;
                        }
                    }
                    ans[i][j]=mul(ans[i][j],cnt);
                    ans[j][i]=mul(ans[j][i],cnt);
                    if(ans[i][j]==0){
                        break;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        ans[i][i]=1;
        for(int j=0;j<n;j++){
            if(j==i){
                continue;
            }
            int cnt=0;
            for(auto h:v[j]){
                if(e[h][i]==e[j][i]-1){
                    cnt++;
                }
            }
            ans[i][i]=mul(cnt,ans[i][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
	return 0;
}