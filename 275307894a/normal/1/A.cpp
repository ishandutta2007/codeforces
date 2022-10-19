#include<iostream>
#include<cmath>
using namespace std;
long long n,m,k;
int main(){
    cin>>n>>m>>k;
    cout<<(long long)ceil(n*1.0/k)*(long long)ceil(m*1.0/k);
    return 0;
}