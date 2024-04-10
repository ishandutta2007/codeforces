#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define M 100
#define Z 50
#define INF 1000000000000000ll
#define long long long
#define X 50
#define Y 2040
#define ZT 1000
#define K 10000100

#define M 2020

using namespace std;


int n,a[M],b[M];

void kill(void){
    cin>>n;
    for (int i=0; i<n; ++i){
        cin>>a[i];
        if (a[i]<0)
            a[i]=-a[i];
    }
    int x=0;
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (a[i]>a[j])
                x++;
    for (int i=0; i<n; ++i){
        b[i]=0;
        for (int j=0; j<i; ++j)
            if (a[j]<a[i])
                b[i]++;
        for (int j=i+1; j<n; ++j)
            if (a[i]>a[j])
                b[i]--;
        if (b[i]<0)
            x+=b[i];
    }
    cout<<x<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    kill();
    return 0;
}