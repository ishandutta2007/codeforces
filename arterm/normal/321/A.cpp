#include <iostream>
#include <string>

#define M 1000

using namespace std;

string s;
int n,a[M],b[M],x,y;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int f(char ch){
    if (ch=='U')
    return 1;
    if (ch=='R')
    return 0;
    if (ch=='L')
    return 2;
    return 3;
}

bool fit(int x, int y){
    if (y==0)
    return x==0;
    if (y<0)
    return x<=0 && x%(-y)==0;
    return x>=0 && x%y==0;
}

int step(int x, int y){
    if (y!=0)
    return x/y;
    return -1;
}

bool fitt(int x, int y, int z, int r){
    int k=step(x,y);
    int d=step(z,r);
    if (k==-1 || d==-1)
    return 1;
    return k==d;
}

void read(void){
    a[0]=b[0]=0;
    cin>>x>>y;
    cin>>s;
    n=s.length();
    for (int i=0; i<n; ++i){
        int k=f(s[i]);
        a[i+1]=a[i]+dx[k];
        b[i+1]=b[i]+dy[k];
    }
    for (int i=0; i<=n; ++i)
    if (fit(x-a[i],a[n]) && fit(y-b[i],b[n]))
    if (fitt(x-a[i],a[n],y-b[i],b[n])){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
}

int main()
{
    read();
    return 0;
}