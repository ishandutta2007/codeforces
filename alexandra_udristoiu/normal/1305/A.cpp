#include<iostream>
#include<algorithm>
using namespace std;
int n, t, i;
int a[105], b[105];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> a[i];
        }
        for(i = 1; i <= n; i++){
            cin>> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for(i = 1; i <= n; i++){
            cout<< a[i] <<" ";
        }
        cout<<"\n";
        for(i = 1; i <= n; i++){
            cout<< b[i] <<" ";
        }
        cout<<"\n";
    }
}