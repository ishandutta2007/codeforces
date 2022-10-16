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

const int N=200005;

char a[N];
int one[N],zero[N],pt[N];
int n,q;

int main(){
    scanf("%d%d",&n,&q);
    scanf("%s",a+1);
    rep(i,1,n){
        pt[i]=pt[i-1];
        one[i]=one[i-1];
        zero[i]=zero[i-1];
        if(i>1&&a[i]==a[i-1]){
            pt[i]++;
            if(a[i]=='1')one[i]++;
            else zero[i]++;
        }
    }
    while(q--){
        int l=read(),r=read();
        print((pt[r]-pt[l]+abs(one[r]-one[l]-(zero[r]-zero[l])))/2+1,'\n');
    }
    return 0;
}