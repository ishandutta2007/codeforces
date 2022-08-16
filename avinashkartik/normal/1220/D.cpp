#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,u,t,c;
    vector<long long int> v[100];
    cin>>n;
    int a[100]={};
    for(int i = 0; i<n; i++){
        cin>>u;
        c = 0;
        t = u;
        while(t%2 == 0){
            c += 1;
            t = t/2;
        }
        a[c] += 1;
        v[c].push_back(u);
    }
    int m = 0;
    for(auto x : a){
        if(x>m)
            m = x;
    }
    cout<<n-m<<endl;
    int flag = 0;
    for(int i = 0; i<100; i++){
        if(a[i] != m || flag == 1)
            for(auto x : v[i])
                cout<<x<<" ";
        else
            flag = 1;
    }
    cout<<endl;
}