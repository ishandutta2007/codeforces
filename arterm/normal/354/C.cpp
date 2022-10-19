#include <iostream>
#include <vector>

#define M 2000100

using namespace std;

int n,a[M],k,s[M];

bool pos(int d){
    if (s[d-1]>0)
        return 0;
    if (k>=d)
        return s[d-1]==0;

    for (int i=d; i+d-1<M; i+=d)
        if (s[i+d-1]-s[i+k]>0)
            return 0;
    return 1;
}

void read(void){
    cin>>n>>k;
    for (int i=0,x; i<n; ++i){
        cin>>x;
        a[x]++;
    }
    s[0]=0;
    for (int i=1; i<M; ++i)
        s[i]=s[i-1]+a[i];

    for (int i=1000100; i>=1; --i)
        if (pos(i)){
            cout<<i<<"\n";
            return;
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("text.in","r",stdin);
    //freopen("text.out","w",stdout);
    read();
    return 0;
}