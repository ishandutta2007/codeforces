#include <bits/stdc++.h>
 
using namespace std;

long long m,n,k;
bool chk(long long  x){
    long long  r = 0;
    for(int i = 1 ;i < n+1 ;i++) r+=min((long long)m,x/i);
    return r < k;
}
 
int main(){
	cin >> n  >> m >> k;
  	long long l = 0,r = (long long) 1e15;
    while(l < r){
        long long m=(l+r)/2;
        if(chk(m))  l= m+1;
        else r = m;
    }
    cout << l;
	return(0);
}