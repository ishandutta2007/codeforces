#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5+5;

#define ld long double

long double ans;
long long coords[MAXN][2];
long long n,H;

long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

long double sqr(long long a) {
    return (long double)a*a;
}

long double dist(long long a, long long b) {
    return sqrt(sqr(coords[a][0]-coords[b][0])+sqr(coords[a][1]-coords[b][1]));
}

long double angle(long double x, long double y) {
    return (y-coords[n-1][1]-H)/(x-coords[n-1][0]);
}

pair<long long,long long> posAngle(long long i) {
    long long xd = coords[i][0]-coords[n-1][0];
    long long yd = coords[i][1]-coords[n-1][1]-H;
    if (xd == 0) {
        if (yd > 0) {
            yd = 1;
        } else {
            yd = -1;
        }
    } else if (yd == 0) {
        if (xd > 0) {
            xd = 1;
        } else {
            xd = -1;
        }
    } else {
        long long gecd = gcd(abs(xd),abs(yd));
        xd /= gecd;
        yd /= gecd;
    }
    if (xd < 0) {
        xd *= -1;
        yd *= -1;
    }
    return make_pair(xd,yd);
}

bool above(pair<long long,long long> posC, pair<long long,long long> posMax) {
    return (posMax.first * posC.second <= posMax.second * posC.first);
}

int main() {
    scanf("%lld %lld",&n,&H);
    for (long long i=0;i<n;i++) {
        scanf("%lld %lld",&coords[i][0],&coords[i][1]);
    }
    ans = dist(n-2,n-1);
    // cout << ans << endl;
    long long curMax = n-2;
    for (long long i=n-3;i>=0;i--) {
        pair<long long,long long> posC = posAngle(i);
        pair<long long,long long> posC1 = posAngle(i+1);
        pair<long long,long long> posMax = posAngle(curMax);
        if (above(posC,posMax) && above(posC1,posMax)) {
            curMax = i;
            ans += dist(i,i+1);
        } else if (!(above(posC,posMax))) {
            
        } else {
            ld x0,x1,x2,y0,y1,y2,xm,ym,xc,yc;
            x0 = coords[i][0];
            y0 = coords[i][1];
            x2 = coords[i+1][0];
            y2 = coords[i+1][1];
            xm = coords[n-1][0];
            ym = coords[n-1][1]+H;
            xc = coords[curMax][0]-xm;
            yc = coords[curMax][1]-ym;
            x1 = (xc*x0*(y2-y0)-xm*yc*(x2-x0)-xc*(x2-x0)*(y0-ym))/(xc*(y2-y0)-yc*(x2-x0));
            y1 = y0+(x1-x0)/(x2-x0)*(y2-y0);
            ans += (x1-x0)/(x2-x0)*dist(i,i+1);
            if (above(posC,posMax)) {
                curMax = i;
            }
            // cout << "----" << endl;
            // cout << (y1-ym)/(x1-xm) << " " << yc/xc << endl;
            // cout << y1 << " " << y0+(x1-x0)/(x2-x0)*(y2-y0) << endl;
            // cout << "----" << endl;
        }
        // cout << ans << endl;
    }
    printf("%.9Lf\n",ans);
}