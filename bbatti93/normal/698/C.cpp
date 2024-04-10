#include <bits/stdc++.h>

using namespace std;

int n, ki, k;
double p[21], q[21], z[1100000];
double t[21][1100000];


int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }
    t[0][0]=1;
    for(int j=0;j<(1<<n);j++) {
        for(int i=0;i<n;i++) {
            if((j&(1<<i))==0) z[j]+=p[i];
        }
    }
    for(int i=0;i<k;i++) {
        for(int j=0;j<(1<<n);j++) {
            if(t[i][j]==0) continue;
            for(int l=0;l<n;l++) {
                if((j&(1<<l))==0) {
                   if(z[j]>0) t[i+1][j|(1<<l)]+=t[i][j]*p[l]/z[j];
                    //cout << j << " " << z[j] << " " << p[l] << endl;
                }
            }
            if(z[j]==0) t[i+1][j]=t[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<(1<<n);j++) {
            if((1<<i)&j) q[i]+=t[k][j];
        }
        cout << setprecision(10) << q[i] << " ";
    }
    cout << endl;
    return 0;
}