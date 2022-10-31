#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[15];
int n;
bool dp(int i, int s){
    if(i == n) return (s%360)==0;
    bool ret = false;
    if(!ret) ret = dp(i+1, s+a[i]);
    if(!ret) ret = dp(i+1, s-a[i]);
    return ret;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    if(dp(0, 0)) cout << "YES";
    else cout << "NO";
}