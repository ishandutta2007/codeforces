#include <iostream>
#include <algorithm>

#define M 100100

using namespace std;

int d[M],a[M],n;


void read(void){
    cin>>n;
    for (int i=0; i<n; ++i)
    cin>>a[i];
}

void kill(void){
    d[0]=-1;
    for (int i=1; i<M; ++i)
    d[i]=M+10;
    for (int i=0; i<n; ++i){
        int j= int(upper_bound(d,d+M,a[i])-d);
        if (d[j-1]<a[i] && a[i]<d[j])
        d[j]=a[i];
    }
    for (int i=M-1; i>=1; --i)
    if (d[i]<=n){
        cout<<i<<"\n";
        return ;
    }
}

int main(){
    read();
    kill();
    return 0;
}