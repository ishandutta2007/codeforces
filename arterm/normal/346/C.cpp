#include <iostream>
#include <algorithm>
#include <vector>

#define M 1001000

using namespace std;

int a,b,n,m=0,x[M],to[M],g[M];

void read(void){
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>x[i];
    cin>>a>>b;
    sort(x,x+n);
    for (int i=0,j; i<n; ){
        x[m++]=x[i];
        j=i;
        while (j<n && x[i]==x[j])
            j++;
        i=j;
    }
}

void kill(void){
    for (int i=0; i<=a-b; i++)
        g[i]=1;

    for (int i=0; i<m; ++i){
        int l=(b+x[i]-1)/x[i];
        int r=a/x[i];
        while (l<=r){
            g[l*x[i]-b]=x[i]-1;
            l++;
        }
    }

    int l=0;
    for (int i=b; i<=a; ++i){
        int j=i-b;
        int r=j+g[j];
        while (l<=r && l<=a-b)
        to[l++]=j;
    }

    int ans=0,x=a-b;
    while (x>0)
        ans++,x=to[x];

    cout<<ans<<"\n";
}



int main(){
    ios_base::sync_with_stdio(0);
    read();
    kill();
    return 0;
}