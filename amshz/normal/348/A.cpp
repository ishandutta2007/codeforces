# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 1e5;
int a[xn];
 
int main(){
    int n;
    cin >> n;
    int mx = 0;
    long long int s = 0;
    for (int i=0; i<n; i++){
    cin >> a[i];
    s += a[i];
    if (a[i] > mx)
        mx = a[i];
    }
    long long int l = mx;
    long long int r = s+1;
    long long int x = (l+r)/2;
    while(l < r){
        x = (l+r)/2;
        if (n*x-s >= 0 and n*x-s >= x)
            r = x;
        else
            l = x+1;
    }
    cout << r;
}