#include <bits/stdc++.h>
#define double long double
using namespace std;

int n;
double a[100001],b[100001];
double ans[2][100001];

double _sqrt(double v) {
    double lo=0,up=1e9;
    for(int i=0;i<200;i++) {
        double md=(lo+up)/2;
        if(md*md<=v) lo=md;
        else up=md;
    }
    return lo;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%Lf",a+i);
    for(int i=0;i<n;i++) scanf("%Lf",b+i);

    double P=0,Q=0;
    for(int i=0;i<n;i++) {
        double T = a[i]+b[i]+Q-P, S = a[i]*P + b[i]*P - a[i];
        ans[0][i] = (-T - _sqrt(T*T + 4*S)) / -2.0;
        ans[1][i] = a[i] + b[i] - ans[0][i];
        P+=ans[0][i];
        Q+=ans[1][i];
    }

    for(int i=0;i<2;i++) {
        for(int j=0;j<n;j++) printf("%.8Lf ",ans[i][j]);
        puts("");
    }
    

    return 0;
}