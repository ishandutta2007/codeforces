#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
bool bin(long long  x){
    int l = 0;
    int r = a.size()-1;
    while(l<= r){
        int m = (l +r)/2;
        if(a[m] == x){
            return true;
        }
        if(a[m] > x){
            r = m -1;
        }
        else{
            l = m + 1;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    long long mx = 0;
    for(int i = 0; i<n; i++){
        long long d;
        cin >> d;
        mx = max(mx, d);
        a.emplace_back(d);
       // cout << d << endl;
    }
    sort(a.begin(), a.end());
    if(a.size() == 0){
        cout << 0;
        return 0;
    }
    if(a.size() == 1){
        cout << 1;
        return 0;
    }
   // cout << bin(7) << endl;
    int c = 0;
    for(int i = 0; i<n; i++){
        bool isTrue = false;
        for(long long x = 1; x<=2*mx; x = 2*x ){
            long long y = x - a[i];
            //cout << i << " " << x << " " << y<< endl;
            if(y<=0){
                continue;
            }
            if(y == a[i]){
                if(i!= 0){
                    if(a[i-1] == y){
                        isTrue =true;
                        break;
                    }
                }
                if(i!= n-1 &&  a[i+1] == y){
                    isTrue =true;
                    break;
                }
                continue;
            }
            if(bin(y)){
                isTrue = true;
                break;
            }
        }
        if(!isTrue){
               // cout << i << endl;
            c += 1;
        }
    }
    cout << c;
}