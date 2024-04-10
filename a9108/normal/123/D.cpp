#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <map>

using namespace std;
#define PB push_back
#define MP make_pair
#define eps 1e-8

string s;
int n;
int rank[20][200000];
int id[200000];
int rn[200000];
int now,nlen;
int h[200000];
long long d[2000000];
int cov[2000000];
int t[200000];
bool emp[200000];
bool cmp(int i,int j){
    if (rank[now][i]!=rank[now][j]) return rank[now][i]<rank[now][j];
    if (i+nlen>=n||j+nlen>=n) return i>j;
    return rank[now][i+nlen]<rank[now][j+nlen];
}

void insert(int i,int l,int r,int ll,int rr,long long delta){
    d[i]+=(rr-ll+1)*(long long)delta;
    if (emp[i]){
        emp[i]=false;
        emp[i*2]=emp[i*2+1]=true;
        d[i*2]=d[i*2+1]=0;
        cov[i*2]=cov[i*2+1]=0;
    }
    if (ll==l&&rr==r){
        cov[i]+=delta;
        return;
    }
    int q=(l+r)/2;
    if (rr<=q) insert(i*2,l,q,ll,rr,1);
    else if (ll>q) insert(i*2+1,q+1,r,ll,rr,1);
    else insert(i*2,l,q,ll,q,1),insert(i*2+1,q+1,r,q+1,rr,1);
}
void remove(int i,int l,int r,int ll,int rr){
    if (l==ll&&r==rr){
        d[i]=cov[i]=0;
        emp[i]=true;
        return;
    }
    if (emp[i]) return;
    int q=(l+r)/2;
    insert(i*2,l,q,l,q,cov[i]);
    insert(i*2+1,q+1,r,q+1,r,cov[i]);
    cov[i]=0;
    if (rr<=q) remove(i*2,l,q,ll,rr);
    else if (ll>q) remove(i*2+1,q+1,r,ll,rr);
    else remove(i*2,l,q,ll,q),remove(i*2+1,q+1,r,q+1,rr);
    d[i]=d[i*2]+d[i*2+1];
    //cout<<"remove:"<<i<<' '<<l<<' '<<r<<' '<<ll<<' '<<rr<<' '<<d[2]<<endl;
}

int main(){
    cin>>s;
    n=s.size();
    for (int i=0;i<n;i++) rank[0][i]=s[i]-'a';
    for (int i=0;i<n;i++) id[i]=i;
    for (int i=0,len=1;len<n;len*=2,i++){
        now=i;nlen=len;
        sort(id,id+n,cmp);
        for (int j=0,ra=-1;j<n;j++){
            if (j==0||cmp(id[j-1],id[j])) ra++;
            rank[i+1][id[j]]=ra;
        }
    }
    //for (int i=0;i<n;i++) printf("%d ",id[i]);puts("");
    for (int i=0;i<n;i++) rn[id[i]]=i;
    memset(h,0,sizeof(h));
    int la=0;
    for (int i=0;i<n;i++){
        if (rn[i]==n-1){
            la=0;
            continue;
        }
        la--;
        la=max(la,-1);
        int j=id[rn[i]+1];
        for (;j+la+1<n&&i+la+1<n&&s[j+la+1]==s[i+la+1];la++);
        //printf("%d %d %d %d\n",i,j,rn[i],la);
        h[rn[i]]=la+1;
    }
    //for (int i=0;i<n-1;i++) printf("%d ",h[i]);puts("");
    memset(d,0,sizeof(d));
    memset(cov,0,sizeof(cov));
    long long ans=n;
    ans=ans*(long long)(n+1);
    ans/=2;
    //cout<<d[1]<<endl;
    memset(t,0,sizeof(t));
    memset(emp,false,sizeof(emp));
    for (int i=0;i<n-1;i++){
        remove(1,1,n,h[i]+1,n);
        /*for (int z=h[i]+1;z<=n;z++) t[z]=0;
        for (int z=1;z<=h[i];z++) t[z]++;
        for (int z=1;z<=n;z++) ans+=t[z];*/
        if (h[i]) insert(1,1,n,1,h[i],1);
        ans+=d[1];
        //cout<<h[i]<<' '<<d[1]<<endl;
    }
    cout<<ans<<endl;
}