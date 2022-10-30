#include <bits/stdc++.h>

using namespace std;

long long n, ki, t, a, b, c;
map<long long, long long> m;
void novel(long long a, long long b, long long c) {
    if(a>b) {
        m[a]+=c;
        novel(a/2,b,c);
    } else if(b>a) {
        m[b]+=c;
        novel(a,b/2,c);
    }
}

long long valasz(long long a, long long b) {
    if(a>b) {
        return m[a]+valasz(a/2,b);
    } else if(b>a) {
        return m[b]+valasz(a,b/2);
    } else return 0;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t;
        if(t==1) {
            cin >> a >> b >> c;
            novel(a,b,c);
        } else {
            cin >> a >> b;
            cout << valasz(a,b) << endl;
        }
    }
    return 0;
}