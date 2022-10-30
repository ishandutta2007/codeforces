#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#define N 1000100
#define M 7000
using namespace std;
int prm[N],tmp[N],pcnt;
vector<vector<long long> > dp;
vector<long long> fac,lcp;
int id[M],nxt[M],cnt;
bool cmp(int i,int j){
    return lcp[i]<lcp[j];
}
long long f(int num,int pf){
    if(num==0) return 1;
    if(pf==cnt) return 0;
    if(dp[num][pf]>=0) return dp[num][pf];
    if(fac[num]%fac[id[pf]]){
        return dp[num][pf]=f(num,pf+1);
    }
    else{
        int j=lower_bound(fac.begin(),fac.end(),fac[num]/fac[id[pf]])-fac.begin();
        return dp[num][pf]=f(j,nxt[pf])+f(num,pf+1);
    }
}
bool np[N];
int main(){
    for(int i=2;i<N;i++){
        if(!np[i]){
            prm[pcnt++]=i;
            tmp[i]=i;
        }
        for(int j=0;j<pcnt&&i*prm[j]<N;j++){
            np[i*prm[j]]=true;
            tmp[i*prm[j]]=prm[j];
            if(i%prm[j]==0) break;
        }
    }
    long long a;
    cin>>a;
    for(long long i=1;i*i<=a;i++){
        if(a%i==0){
            fac.push_back(i);
            if(a/i!=i){
                fac.push_back(a/i);
            }
        }
    }
    sort(fac.begin(),fac.end());
    lcp.resize(fac.size());
    for(int i=0;i<fac.size();i++){
        if(fac[i]-1<=1) continue;
        if(fac[i]-1<N){
            long long j=tmp[fac[i]-1],r=fac[i]-1;
            while(r%j==0) r/=j;
            if(r==1){
                lcp[i]=tmp[fac[i]-1];
                id[cnt++]=i;
            }
            continue;
        }
        bool flag=true;
        for(int j=0;j<pcnt;j++){
            if((fac[i]-1)%prm[j]==0){
                lcp[i]=prm[j];
                flag=false;
                break;
            }
        }
        if(flag){
            lcp[i]=fac[i]-1;
            id[cnt++]=i;
        }
        else{
            long long j=fac[i]-1;
            while(j%lcp[i]==0) j/=lcp[i];
            if(j==1){
                id[cnt++]=i;
            }
        }
    }
    sort(id,id+cnt,cmp);
    for(int i=0,j=0;i<cnt;i++){
        while(j<cnt&&lcp[id[j]]<=lcp[id[i]]) j++;
        nxt[i]=j;
    }
    dp.assign(fac.size(),vector<long long>(cnt,-1));
    cout<<f(fac.size()-1,0)<<endl;
    return 0;
}