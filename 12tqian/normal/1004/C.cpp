#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
static vector<int> a;
static int l [MAX];
static int r [MAX];
static vector<int> b;
static vector<int> c;
int bin(int x){
    //smallest strictly larger than x
    int lo = 0;
    int hi = c.size() -1;
    while(lo<= hi){
        int m = (lo + hi)/2;
        if(c[m] <=x){
            lo = m+1;
        }
        if(c[m] >x){
            hi = m- 1;
        }
    }
    return lo;
}
int main(){
    int n;
    cin >> n;
    for(int i =0 ; i<MAX; i++){
        l[i] = 1000000;
        r[i] = -1;
    }
    for(int i = 0; i<n; i++){
        int x;
        x -= 1;
        cin >> x;
        l[x] = min(l[x], i);
        r[x] = max(r[x], i);
        a.emplace_back(x);
    }
    for(int i = 0; i<MAX; i++){
        if(l[i] != 1000000){
            b.emplace_back(l[i]);
        }
        if(r[i] != -1){
            c.emplace_back(r[i]);
        }
    }
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long total = 0;
    for(int x: b){
        int y = bin(x);
        total += (c.size() - 1 - y + 1);
    }
    cout << total;
    return 0;
}