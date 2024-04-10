#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int a[100100];
int rec(int l, int r, char c) {
    if(l == r) {
        return s[l] != c;
    }
    int mid = (l + r)/2;
    int res=rec(l, mid, c+1);
    for(int i = mid+1; i <= r; i++) {
        if(s[i] != c) res++;
    }
    int res2=rec(mid+1, r, c+1);
    for(int i = l; i <= mid; i++) {
        if (s[i] != c) res2++;
    }
    return min(res, res2);
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> s;
        cout << rec(0, n-1, 'a') << "\n";
    }
}