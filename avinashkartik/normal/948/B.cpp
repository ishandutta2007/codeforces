#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const int N = 1e6 + 3;
ll mod = 1e9 + 7;
ll prime[N]; 

void SieveOfEratosthenes(int n){
    for (int p=2; p<=n; p++){
        if (prime[p] == 0) {
            prime[p] = p;
            for (int i=p*2; i<=n; i += p){
                prime[i] = p;
                //cout<<i<<" "<<p<<endl;
            }
        } 
    }
} 

ll n,k,a,b,m=N,k1;

int main(){
    cin>>n;
    SieveOfEratosthenes(n);
    for(int i = n; i > 1; i--){
        //cout<<prime[i]<<" ";
        if(prime[i] == i && n%i == 0){
            //cout<<i<<" ";
            a = i;
            break;
        }
    }
    //cout<<a<<endl;
    for(int i = n-a+1; i <= n; i++){
        if(prime[i] == i) b = i;
        else b = i - prime[i] + 1;
        m = min(m,b);
    }
    cout<<m<<endl;
}