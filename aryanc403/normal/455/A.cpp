#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
const lli INF = 0xFFFFFFFFFFFFFFFL;
const lli MOD = 1000000007L;
    lli T,n,in,i,m,j,k;
    map<lli,lli> a;
    map<lli,lli> :: iterator it,jt;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld",&n);
    lli m=0;
    fo(i,n)
    {
        scanf(" %lld",&in);
        it=a.find(in);
        if(it==a.end())
        {
            a.insert(mp(in,1));
            m++;
        }
        else
        {
            it->Y++;
        }
        
    }
    lli cnt[m+2]={0,0};
    it=a.begin();
    i=2;
    cnt[i]=(it->X)*(it->Y);
    jt=it;
    it++;
    //cout<<cnt[i]<<" "<<i<<endl;
    i++;
    while(it!=a.end())
    {
        if((it->X)!=(jt->X)+1)
        {
            cnt[i-2]=max(cnt[i-2],cnt[i-1]);
        }
        else
        {
            cnt[i-2]=max(cnt[i-2],cnt[i-3]);
        }
        cnt[i]=cnt[i-2]+(it->X)*(it->Y);
        //cout<<cnt[i]<<" "<<i<<endl;
        i++;
        jt=it;
        it++;
    }
    
    cout<<max(cnt[m+1],cnt[m]);
    return 0;
}