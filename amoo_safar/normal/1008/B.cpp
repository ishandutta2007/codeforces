#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;

int main(){
    ll n ,a ,b;
    cin >> n >> a >>b;
    ll m = max(a,b);
    ll d;
    for(int i =1;i<n;i++){
        cin >> a >> b;
        d=max(a,b);
        if(d <= m){
            m=d;
        }else{
            if(a+b-d > m){
                cout << "NO" ;
                return 0;
            }else{
                m = a+b-d;
            }
        }
    }
    cout << "YES";
    return 0;
}