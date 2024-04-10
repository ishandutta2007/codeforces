#include <bits/stdc++.h>
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;
void A(){
    ll n, sk=2;
    cin >> n;
    ll fib[n+1] = {0};
    fib[0]=1;
    fib[1]=1;
    for(ll i=2;i<=n;i++)fib[i]=fib[i-1]+fib[i-2];
    cout << "O";
    for(ll i=2;i<=n;i++){
        if(fib[sk]==i){
            sk++;
            cout << "O";
        }else if(fib[sk]<i){sk++;cout << "o";}
        else if(fib[sk]>i) cout << "o";
    }
}
void B(){
    SPEED;
    ll n, k;
    cin >> n >> k;
    map<string, string> mp;
    for(ll i=0;i<n;i++){
        string name, ip;
        cin >> name >> ip;
        mp[ip]=name;
    }
    for(ll i=0;i<k;i++){
        string command, ip;
        cin >> command >> ip;
        ip.erase(ip.length()-1, 1);
        cout << command << " " << ip << "; #" << mp[ip] << endl;
    }
}
int main()
{
    SPEED;
    B();
}