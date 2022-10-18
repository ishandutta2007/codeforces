#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

const int mod=998244353;
void add(int& x,int y){
    x+=y;
    x-=mod*(x>=mod);
    x+=mod*(x<0);
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
vector<int> v;
vector<vector<int> > dp,vis,dp2,dp3,vis2,vis3;
int cal(int i,int t1,int t2,int t3){
    if(i==dp.size()){
        return 1;
    }
    int h=t1*4+t2*2+t3;
    if(vis[i][h]){
        return dp[i][h];
    }
    vis[i][h]=1;
    for(int a=0;a<=1;a++){
        if(t1 && a>(v[i])){
            continue;
        }
        for(int b=0;b<=1;b++){
            if(t2 && b>v[i]){
                continue;
            }
            for(int c=0;c<=1;c++){
                if(t3 && c>v[i]){
                    continue;
                }
                if(a==1 && b==1 && c==0){
                    continue;
                }
                if(a==0 && b==0 && c==1){
                    continue;
                }
                int c1=0,c2=0,c3=0;
                if(t1==1 && a==v[i]){
                    c1=1;
                }
                if(t2==1 && b==v[i]){
                    c2=1;
                }
                if(t3==1 && c==v[i]){
                    c3=1;
                }
                add(dp[i][h],cal(i+1,c1,c2,c3));
            }   
        }
    }
    return dp[i][h];
}
int cal2(int i,int t1,int t2,int t3){
    if(i==dp.size()){
        return 1;
    }
    int h=t1*4+t2*2+t3;
    if(vis2[i][h]){
        return dp2[i][h];
    }
    vis2[i][h]=1;
    for(int a=0;a<=1;a++){
        if(t1 && a>(v[i])){
            continue;
        }
        for(int b=0;b<=1;b++){
            if(t2 && b>v[i]){
                continue;
            }
            for(int c=0;c<=1;c++){
                if(t3 && c>v[i]){
                    continue;
                }
                if(a==1 && b==1 && c==0){
                    continue;
                }
                if(a==1 && b==0 && c==1){
                    continue;
                }
                if(a==0 && b==0 && c==1){
                    continue;
                }
                if(a==0 && b==1 && c==0){
                    continue;
                }
                int c1=0,c2=0,c3=0;
                if(t1==1 && a==v[i]){
                    c1=1;
                }
                if(t2==1 && b==v[i]){
                    c2=1;
                }
                if(t3==1 && c==v[i]){
                    c3=1;
                }
                add(dp2[i][h],cal2(i+1,c1,c2,c3));
            }   
        }
    }
    return dp2[i][h];
}
int cal3(int i,int t1,int t2,int t3){
    if(i==dp.size()){
        return 1;
    }
    int h=t1*4+t2*2+t3;
    if(vis3[i][h]){
        return dp3[i][h];
    }
    vis3[i][h]=1;
    for(int a=0;a<=1;a++){
        if(t1 && a>(v[i])){
            continue;
        }
        for(int b=0;b<=1;b++){
            if(t2 && b>v[i]){
                continue;
            }
            for(int c=0;c<=1;c++){
                if(t3 && c>v[i]){
                    continue;
                }
                if(a+b+c==2 || a+b+c==1){
                    continue;
                }
                int c1=0,c2=0,c3=0;
                if(t1==1 && a==v[i]){
                    c1=1;
                }
                if(t2==1 && b==v[i]){
                    c2=1;
                }
                if(t3==1 && c==v[i]){
                    c3=1;
                }
                add(dp3[i][h],cal3(i+1,c1,c2,c3));
            }   
        }
    }
    return dp3[i][h];
}
int main(){
    AquA;
    string x;
    cin >> x;
    int n=x.size();
    v.resize(n);
    int z=0;
    for(int i=0;i<n;i++){
        v[i]=x[i]-'0';
        z=mul(2,z);
        add(z,v[i]);
    }
    dp.resize(n,vector<int>(8));
    vis=dp;
    dp2=dp;
    dp3=dp;
    vis2=vis;
    vis3=vis;
    int ans=mul(z+1,mul(z+1,z+1));
    add(ans,-mul(3,cal(0,1,1,1)));
    add(ans,mul(3,cal2(0,1,1,1)));
    add(ans,-cal3(0,1,1,1));
    cout << ans << "\n";
    return 0;
}