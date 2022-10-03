#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long n;
    cin>>n;
    int L[n];
    for (int i=0; i<n; i++){
        cin>>L[i];
    }
    sort(L, L+n);
    long long t1=1, t2=1;
    if (L[0]==L[n-1]){
        cout<<0<<' '<<(long long) n*(n-1)/2<<endl;
        return 0;
    }
    for (int i=1; i<n; i++){
        if (L[i]==L[i-1]){
            t1++;
        }
        else{
            break;
        }
    }
    for (int i=n-2; i>=0; i--){
        if (L[i]==L[i+1]){
            t2++;
        }
        else{
            break;
        }
    }
    cout<<L[n-1]-L[0]<<' '<<t1*t2<<endl;

    return 0;
    }