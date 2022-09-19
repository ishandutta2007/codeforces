#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll p[10000];
ll c[10000];
int main(){
    ll n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        cin >> p[i];
    }
    for(int i =0;i<n;i++){
        cin >> c[i];
    }
    ll t = 1;
    for(int i = 0;i<n-1 ;i++){
        if( c[p[i]-1]!=c[i+1] ) t++;
    }
    cout << t << endl;
}