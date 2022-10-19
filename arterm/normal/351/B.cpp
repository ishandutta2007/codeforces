#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#define M 3030
#define N 5000500

using namespace std;

int n,a[M],x=0;

void read(void){
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (a[i]>a[j])
                x++;
}

void kill(void){
    if (x%2==0)
        cout<<2.0*x<<"\n";
    else
        cout<<1.0*(2*x-1)<<"\n";
}



int main(){
    cout.precision(10);
    cout<<fixed;
    ios_base::sync_with_stdio(0);
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    read();
    kill();
    return 0;
}