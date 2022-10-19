#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    map<int,int> trad;
    for(int i = 0; i < n; i++) trad[a[i]] = i;
    for(int i = 0; i < n; i++) b[i] = trad[b[i]];
    int maxVisto = -1;
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(maxVisto > b[i]) res++;
        maxVisto = max(maxVisto,b[i]);
    }
    cout<<res<<'\n';
}