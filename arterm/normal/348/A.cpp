#include <iostream>
#include <algorithm>
#include <numeric>

#define long long long
#define M 100100

using namespace std;

long  n,a[M],s=0;

int main(){
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i],s+=a[i];
    long m=*max_element(a,a+n);
    cout<<max(m,(s+n-2)/(n-1))<<"\n";
    return 0;
}