#include <bits/stdc++.h>

using namespace std;

const long long inf = 10000000000000000ll;

long long n, ki, r, e;
long long x[50001], a[50001], b[50001], c[50001], d[50001];
long long t0[100011], t1[100011];


int main()
{
    cin >> n >> r >> e;
    r--;
    e--;
    for(int i=0;i<n;i++) {
        cin >> x[i];
    }
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    for(int i=0;i<n;i++) {
        cin >> c[i];
    }
    for(int i=0;i<n;i++) {
        cin >> d[i];
    }
    for(int i=0;i<=2*n+7;i++) t0[i]=t1[i]=inf;
    t0[0]=0;
    for(int i=0;i<n;i++) {
        if(i!=0) t0[0]=inf;
        for(int j=0;j<=2*n+5;j++) {
            t1[j]=t0[j];
            if(t1[j]>inf) t1[j]=inf;
            t0[j]=inf;
        }
        for(int j=0;j<=2*n+5;j++) {
            if(j==0 && i!=n-1) continue;
            long long tmp1;
            if(i==r) {
                t0[j]=t1[j+1]+c[i]+x[i];
                if(j>=1) {
                    tmp1=t1[j-1]+d[i]-x[i];
                    if(tmp1<t0[j]) t0[j]=tmp1;
                }
            } else if(i==e) {
                t0[j]=t1[j+1]+a[i]+x[i];
                if(j>=1) {
                    tmp1=t1[j-1]+b[i]-x[i];
                    if(tmp1<t0[j]) t0[j]=tmp1;
                }
            } else {
                if(j!=1) {
                    t0[j]=t1[j]+c[i]+b[i];
                    tmp1=t1[j]+a[i]+d[i];
                    if(tmp1<t0[j]) t0[j]=tmp1;
                } else {
                    if(e<i) {
                        t0[j]=t1[j]+c[i]+b[i];
                    } else {
                        t0[j]=t1[j]+a[i]+d[i];
                    }
                }
                tmp1=t1[j+2]+a[i]+c[i]+2*x[i];
                if(tmp1<t0[j]) t0[j]=tmp1;
                if(j>=2) {
                    tmp1=t1[j-2]+b[i]+d[i]-2*x[i];
                    if(tmp1<t0[j]) t0[j]=tmp1;
                }
            }
        }
    }
    cout << t0[0] << endl;
    return 0;
}