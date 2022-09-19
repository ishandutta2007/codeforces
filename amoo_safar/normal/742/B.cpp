#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll const MAXN = 200001;
ll a[MAXN];
ll b[MAXN];
int main(){
    ll n,x,el;
    cin >> n >> x;
    for(int i = 0;i<n;i++){
        cin >> el;
        a[el]++;
        b[i] = el;
    }
    ll t = 0;
    for(int i =0 ;i<n;i++){
        //cout << x <<  " "<<b[i] <<  " "<< ((int)x^b[i]) << endl;
        if(x!=0)t = t+a[x^b[i]];
        else t = t+a[x^b[i]]-1;
    }
    cout << t/2;
    return 0;
}