// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

char ss[1005];
int a[26],b[26],c[26];
int lena,lenb,lenc;

int gao(int *a){
    scanf("%s",ss);
    for(int i=0;ss[i]!='\0';i++)a[ss[i]-'A']++;
    return strlen(ss);
}

vector<int> s1,s2,s3,t1,t2,t3;
vector<pii> ans;
void sol(vector<int> &a,vector<int> &b){
    ans.pb({a.back(),b.back()});
    a.pop_back(),b.pop_back();
}

int main(){
    lena=gao(a),lenb=gao(b),lenc=gao(c);
    int lim=min({lena,lenb,lenc}),tot=0;
    for(int i=0;i<26;i++){
        // printf("%d %d %d\n",a[i],b[i],c[i]);
        int cur=0,X=0,Y=0,Z=0;
        for(int x=0;x<=min(a[i],b[i]);x++)
            for(int y=0;y<=min(b[i]-x,c[i])&&x+y<=lim-tot;y++){
                int z=min({a[i]-x,c[i]-y,lim-x-y-tot});
                if(x+y+z>cur)
                    cur=x+y+z,X=x,Y=y,Z=z;
            }
        tot+=cur;
        t3.insert(t3.end(),X,i),a[i]-=X,b[i]-=X;
        t1.insert(t1.end(),Y,i),b[i]-=Y,c[i]-=Y;
        t2.insert(t2.end(),Z,i),a[i]-=Z,c[i]-=Z;
    }
    for(int i=0;i<26;i++){
        // printf("a[%d]=%d,b[%d]=%d,c[%d]=%d\n",i,a[i],i,b[i],i,c[i]);
        s1.insert(s1.end(),a[i],i);
        s2.insert(s2.end(),b[i],i);
        s3.insert(s3.end(),c[i],i);
    }
    // cerr<<"!\n";
    while(!t1.empty())sol(t1,s1);
    while(!t2.empty())sol(t2,s2);
    while(!t3.empty())sol(t3,s3);
    while(!s1.empty()&&(!s2.empty()||!s3.empty())){
        if(SZ(s2)>SZ(s3))sol(s1,s2);
        else sol(s1,s3);
    }
    while(!s2.empty()&&!s3.empty())sol(s2,s3);
    // cerr<<"!\n";
    vector<int> E;E.insert(E.end(),10000,0);
    while(!s1.empty())sol(s1,E);
    while(!s2.empty())sol(s2,E);
    while(!s3.empty())sol(s3,E);
    print(SZ(ans),'\n');
    for(auto [x,y]:ans)
        printf("%c%c\n",x+'A',y+'A');
    return 0;
}