#include <bits/stdc++.h>
using namespace std;
const long long MAX = 100005;
vector<long long> c;
vector<long long> cap;
int main(){
    long long n, k;
    long long fin = 0;
    cin >> n>> k;
    long long all = 0;
    for(long long i = 0; i<n; i++){
        long long d;
        cin >> d;
        c.emplace_back(d);
        all += c[i];
    }
    long long prev=  -50;
    for(long long i = 0; i<k; i++){
        long long d;
        cin >> d;
        cap.emplace_back(d-1);
        if(d!= 1 && prev == (d-2+n)%n){
             //   cout << " hi" << endl;
            fin += (c[d-1] *c[prev]);
        }
        fin -= (c[d-1] * c[(d-2+n)%n] +c[d-1]*c[d%n]);
        prev = d-1;
    }
    if(cap[k-1] == n-1&& cap[0] == 0){
        fin += (c[0] *c[n-1]);
    }
    for(long long i = 0; i<n; i++){
        fin += (c[i]*c[(i+1)%n]);
    }
   // cout << fin << endl;
    long long total = 0;
    long long sum = 0;
    for(long long i: cap){
        total += (c[i] *c[i]);
        sum += c[i];
    }
    all -= sum;
    fin += all*sum;
    fin += ((sum*sum - total)/2);
    cout <<fin;
    return 0;
}