#include <iostream>

#define M 404

using namespace std;

int a[M],n,t[M],w[M],y[M];

void express(int x, int *y){
    for (int i=1; i<=n; ++i)
        *(y+i)=x/a[i],x%=a[i];
}

int sum(int *x){
    int s=0;
    for (int i=1; i<=n; ++i)
        s+=(a[i]*x[i]);
    return s;
}

int col(int *x){
    int s=0;
    for (int i=1; i<=n; ++i)
        s+=x[i];
    return s;
}

bool isGood(int r){
    for (int i=1; i<=n; ++i)
        y[i]=0;
    for (int i=1; i<=r; ++i)
        y[i]=t[i];
    y[r]++;
    int s=sum(y);
    express(s,w);
    if (col(w)<=col(y))
        return 1;
    for (int i=1; i<=n; ++i)
        if (w[i]!=y[i])
            return 0;
    return 1;
}

void kill(void){
    int ans;
    bool pos=1;
    for (int i=n; i>=2; --i){
        express(a[i-1]-1,t);
        if (t[i]>0)
            for (int j=i; j<=n; ++j)
                if (!isGood(j))
                    if (pos)
                        pos=0,ans=sum(y);
                    else
                        ans=min(ans,sum(y));
    }
    if (pos)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}

void read(void){
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
}

int main(){
    read();
    kill();
    //system("pause");
    return 0;
}