#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <cmath>

using namespace std;

int a,b,c,n,t[10000], x[3000],y[3000], xx[3000], yy[3000], s[3000];

long long tri(int a) {
    return ((long long)a)*(a-1)*(a-2)/6;
}
int du(int a) {
    return a*(a-1)/2;
}

int firq(int x0, int x1, int y0, int y1) {
    return x1*y0-x0*y1;
}

int has(const void*v, const void*u) {
    int i=*(int*)v, j=*(int*)u;
    return firq(xx[i],xx[j], yy[i],yy[j]);
}

int main()
{
    cin >> n;
    long long ki=3*tri(n);
    for(int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            s[j]=j;
            xx[j]=x[j]-x[i];
            yy[j]=y[j]-y[i];
            if(yy[j]<0 || (yy[j]==0 && xx[j]<0)) {
                xx[j]=-xx[j];
                yy[j]=-yy[j];
            }
        }
        xx[i]=xx[n-1];
        yy[i]=yy[n-1];
        xx[n-1]=1000;
        yy[n-1]=1;
        qsort(s,n-1,sizeof(int), has);
        int l=0;
        for(int j=1;j<n; j++) {
            if(firq(xx[s[j-1]],xx[s[j]],yy[s[j-1]],yy[s[j]])!=0) {
                ki-=du(j-l);
                l=j;
            }
        }
    }

    cout << ki/3;
    return 0;
}