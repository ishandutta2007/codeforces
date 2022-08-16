#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b){
    if (b == 0) return a;
    return gcd(b,a%b);
} 

int main(){
    int n,t,l[1000003],a[1000003]={},min;
    cin >> t;
    while(t--){
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>l[i];
            //cout<<l[i];
        }
        min = l[n-1];
        int c = 0;
        for(int i = n-1; i>=0; i--){
            if(l[i] > min) c++;
            else min = l[i];
        }
        cout<<c<<endl;
    }
}