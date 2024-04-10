#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const double INF = 1e100;

double dist(pii a, pii b) {
    return sqrt(1.0 * (a.first - b.first) * (a.first - b.first)
            + 1.0 * (a.second - b.second) * (a.second - b.second));
}

pii b[3],arr[100001];
int n;

void upd(double *d, int *i, double _d, int _i, int t) {
    for(int j=1;j>=t;j--) d[j] = d[j-1], i[j] = i[j-1];
    d[t] = _d;
    i[t] = _i;
}
int main() {
    for(int i=0;i<3;i++) scanf("%d%d",&b[i].first,&b[i].second);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&arr[i].first,&arr[i].second);

     double d1[2] = {INF, INF}, d2[2] = {INF, INF};
     int i1[2],i2[2];

     for(int i=0;i<n;i++) {
         double dd1 = dist(b[0], arr[i]) - dist(b[2],arr[i]), dd2 = dist(b[1], arr[i]) - dist(b[2],arr[i]);
         if(d1[0] > dd1) {
             upd(d1,i1,dd1,i,0);
         } else if(d1[1] > dd1) {
             upd(d1,i1,dd1,i,1);
         }
         
         if(d2[0] > dd2) {
             upd(d2,i2,dd2,i,0);
         } else if(d2[1] > dd2) {
             upd(d2,i2,dd2,i,1);
         }
     }

     double sum=0;
     for(int i=0;i<n;i++) sum += dist(b[2],arr[i]);
     
     double ans = min(2*sum + d1[0], 2*sum + d2[0]);

     if(n!=1) {
         if(i1[0] == i2[0]) {
             ans = min(ans, 2*sum + d1[0] + d2[1]);
             ans = min(ans, 2*sum + d2[0] + d1[1]);
         } else {
             ans = min(ans, 2*sum + d2[0] + d1[0]);
         }
     }

     printf("%.10lf\n",ans);

    
    return 0;
}