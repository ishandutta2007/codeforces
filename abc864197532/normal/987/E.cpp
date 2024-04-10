#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
    int n,tmp;
    cin >> n;
    int a[n], p[n];
    int ans = 0;
    fop (i,0,n) {
        cin >> a[i];
        a[i]--;
        p[a[i]] = i;
    }
    fop (i,0,n) {
        if (p[i] == i) continue;
        swap(a[p[i]], a[i]);
        swap(p[a[p[i]]], p[a[i]]);
        ans ^= 1;
    }
    if (ans == n % 2) cout << "Petr" << endl;
    else cout << "Um_nik" << endl;
}