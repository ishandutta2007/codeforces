#include <bits/stdc++.h>

using namespace std;

int dg(int a) {
    int out=0;
    for(;a>0;a/=10) out++;
    return out;
}

int a[200001], n, k;
long long ki, t[11];
unordered_map<int,int> m[11];

int main()
{
    scanf("%d%d", &n, &k);
    t[0]=1;
    for(int i=1;i<=10;i++) t[i]=10*t[i-1];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) {
        long long l=((long long)a[i]*10)%k;
        for(int j=1;j<11;j++) {
            m[j][l]++;
            l=(10*l)%k;
        }
    }
    for(int i=0;i<n;i++) {
        int d=dg(a[i]), b=(k-a[i]%k)%k;
        ki+=m[d][b];
        if(a[i]*((t[d]+1)%k)%k==0) ki--;
    }
    cout << ki << endl;
    return 0;
}