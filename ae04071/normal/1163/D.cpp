#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

char tar[1010],s[101],t[101];
int ps[101],pt[101],dp[1010][51][51],vis[1010][51][51];
int pps[51][26],ppt[51][26];
int l,n,m;

void getpi(char *str,int *arr,int n) {
    int i=0;
    for(int j=1;j<n;j++) {
        while(i!=0 && str[i]!=str[j]) i=arr[i-1];
        if(str[i]==str[j]) arr[j]=++i;
    }
}
void comp(char *str,int *arr, int n, int f) {
    for(int i=0;i<n;i++) {
        for(int ch=0;ch<26;ch++) {
            int j=i;
            while(j!=0 && str[j]!=ch+'a') j=arr[j-1];
            if(str[j]==ch+'a') j++;
            if(!f) pps[i][ch]=j;
            else ppt[i][ch]=j;
        }
    }
}

int DP(int idx,int si,int ti) {
    if(idx==l) return 0;

    int &ret=dp[idx][si][ti];
    if(vis[idx][si][ti]) return ret;
    vis[idx][si][ti]=1;
    ret=-1e9;

    for(int nx=(tar[idx]=='*' ? 0 : tar[idx]-'a');nx<=(tar[idx]=='*' ? 25 : tar[idx]-'a');nx++) {
        int ssi=pps[si][nx],tti=ppt[ti][nx];
        /*
        int ssi=si,tti=ti;
        while(ssi!=0 && nx+'a' != s[ssi]) ssi=ps[ssi-1];
        while(tti!=0 && nx+'a' != t[tti]) tti=pt[tti-1];
        if(s[ssi]==nx+'a') ssi++;
        if(t[tti]==nx+'a') tti++;
        */

        int ad=0;
        if(ssi==n) ad++,ssi=ps[ssi-1];
        if(tti==m) ad--,tti=pt[tti-1];
        
        ret = max(ret, DP(idx+1,ssi,tti)+ad);
    }
    return ret;
}


int main() {
    scanf("%s%s%s",tar,s,t);

    l=strlen(tar);
    n=strlen(s);
    m=strlen(t);

    getpi(s,ps,n);
    getpi(t,pt,m);
    comp(s,ps,n,0);
    comp(t,pt,m,1);

    printf("%d\n",DP(0,0,0));

    return 0;
}