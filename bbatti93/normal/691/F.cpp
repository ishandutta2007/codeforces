#include <bits/stdc++.h>

using namespace std;

long long t[3000001], n, a, m;
long long ki[3000001], s;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &a);
        t[a]++;
    }
    for(int i=1;i<=3000000;i++) {
        if(!t[i]) continue;
        for(int j=1;j*i<=3000000;j++) {
            ki[i*j]+=t[i]*t[j];
            if(j==i) ki[i*j]-=t[i];
        }
    }
    for(int i=2;i<=3000000;i++) ki[i]+=ki[i-1];
    cin >> m;
    s=n;
    s*=(n-1);
    for(int i=0; i<m;i++) {
        scanf("%d", &a);
        printf("%I64d\n",s-ki[a-1]);
    }
    return 0;
}