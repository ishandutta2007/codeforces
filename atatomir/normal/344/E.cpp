#include <iostream>
#include <cstdio>

using namespace std;

long n,m,pos;
long long h[100005],r[100005];
char s[1200000];
long long i,j,mij;

long long getLongLong(){
    long long ans=0;
    while(s[pos] == ' ') pos ++;
    while((s[pos]>='0')&&(s[pos]<='9')){
        ans = ans*10+s[pos]-'0';
        pos++;
    }
    return (ans);
}

long cb(long long x){
    long i=1,j=m,mij;
    do {
        mij = (i+j)/2;
        if(x <= r[mij])
            j = mij - 1;
        else
            i = mij+1;
    }   while(i<=j);
    return j;
}

int check(long long d){
    long pos = 1,i,did;
    for(i=1;i<=n;i++){
        if(h[i] <= r[pos]){
            while(r[pos]-h[i] <= d) pos++;
        } else {
            if(h[i]-r[pos] > d) return 0;
            did = cb(h[i]);
            while(r[did+1]-r[pos] + min(h[i]-r[pos],r[did+1]-h[i]) <= d) did++;
            pos = did+1;
        }
        if(pos > m) return 1;
    }
    if(pos <= m) return 0;
    return 1;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%ld %ld\n",&n,&m);
    pos=0;gets(s);
    for(i=1;i<=n;i++) h[i] = getLongLong();
    pos=0;gets(s);
    for(i=1;i<=m;i++) r[i] = getLongLong();

    r[m+1] = 1LL << 60;

    i=0;j=1e11;
    do {
        mij = (i+j)/2;
        if(check(mij))
            j = mij-1;
        else
            i = mij+1;
    }   while(i<=j);

    printf("%I64d",i);

    return 0;
}