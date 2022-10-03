#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int L[100 * 1000 + 10];

int main(){
    //freopen("input.txt", "r", stdin);
    long long n, k;
    cin>>n>>k;
    for (int i=0; i<n; i++){
        cin>>L[i];
    }
    sort(L, L+n);
    long long cnt=1;
    for (int i=1; i<n; i++){
        if (L[i]==L[i-1]){
            cnt++;
        }
        else{
            if (k<=cnt*(i-cnt)){
                cout<<L[i-1]<<' '<<L[(k-1)/cnt]<<endl;
                //cout<<"debug1"<<endl;
                return 0;
            }
            k-=(i-cnt)*cnt;
            if (k<=cnt*cnt){
                cout<<L[i-1]<<' '<<L[i-1]<<endl;
                //cout<<"debug2"<<endl;
                return 0;
            }
            k-=cnt*cnt;
            if (k<=(n-i)*cnt){
                cout<<L[i-1]<<' '<<L[i+(k-1)/cnt]<<endl;
                //cout<<"debug3"<<endl;
                return 0;
            }
            k-=(n-i)*cnt;
            cnt=1;
        }
    }
    if (k<=cnt*(n-cnt)){
        cout<<L[n-1]<<' '<<L[(k-1)/cnt]<<endl;
        //cout<<"debug4 "<<(k-1)/cnt<<endl;
        return 0;
    }
    k-=(n-cnt)*cnt;

    if (k<=cnt*cnt){
        cout<<L[n-1]<<' '<<L[n-1]<<endl;
        //cout<<"debug2"<<endl;
        return 0;
    }



    return 0;
}