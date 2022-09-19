#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    deque<ll> q1;
    deque<ll> q2;
    ll a[n];
    ll s = 0;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        s += a[i];
    }
    if(s%3==0 and n > 2){
        //cout << 2;
        ll ps = s/3;
        s = 0;
        for(int i = 0;i<n;i++){
            s+=a[i];
            if(s == ps) q1.push_back(i);
        }
        s = 0;
        for(int i = n - 1;i >= 0;i--){
            s+=a[i];
            if(s == ps) q2.push_front(i);
        }
        //cout << 2;
        s = 0;
        ll f1,f2;
        while(q1.size() > 0 and q2.size() > 0){
            f1 = q1.front();
            f2 = q2.front();
            //cout << f1 << " " << f2 << endl;
            if(f1+1 >= f2){
                q2.pop_front();
            } else {
                q1.pop_front();
                s += q2.size();
            }
        }
        cout << s;
    } else{
        cout << 0;
    }
    return 0;
}