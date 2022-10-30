#include <bits/stdc++.h>

using namespace std;

long long n, l, m, b1, b2, ki;
long long t[100010];


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> l;
    t[0]=t[n+1]=l-1;
    for(int i=1;i<=n;i++) {
        cin >> t[i];
    }
    ki=0;
    for(int i=1;i<=n;i++) {
        if(t[i]>l && t[i-1]<=l) ki++;
    }
    for(int i=0;i<m;i++) {
        cin >> b1;
        if(b1==0) {
            cout << ki << "\n";
            continue;
        }
        cin >> b1 >> b2;
        if(t[b1]<=l && t[b1]+b2>l) {
            ki++;
            if(t[b1-1]>l) ki--;
            if(t[b1+1]>l) ki--;
        }
        t[b1]+=b2;
    }
    return 0;
}