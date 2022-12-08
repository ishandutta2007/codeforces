#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define INF 1073741823

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> ds(n);
    
    int mn1 = 1e9;
    int mn2 = 1e9;
    for(int &d : ds) {
        cin >> d;
        if(d <= mn1) {
            mn2 = mn1;
            mn1 = d;
        } else if(d < mn2) {
            mn2 = d;
        }
    }
    int res = (mn1+1)/2 + (mn2+1)/2;
    for(int i = 0; i < n - 1; i ++) {
        int a = ds[i];
        int b = ds[i+1];
        if(a < b) { swap(a,b); }
        int dif = a - b;
        int cur = 0;
        if(dif * 2 < a) {
            a -= dif * 2;
            b -= dif;
            cur = dif + (a/3) * 2 + a%3;
        } else {
            cur = b + (a-2*b+1)/2;
        }
        res = min(res,cur);
    }
    for(int i = 0; i < n - 2; i ++) {
        int a = ds[i];
        int b = ds[i+2];
        res = min(res,(a+b+1)/2);
    }
    cout << res;
    return 0;
}