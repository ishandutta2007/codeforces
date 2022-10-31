#include <bits/stdc++.h>

using namespace std;

long long n, ki, t[500001], mini, maxi, su, su2, mi, ma, ku[500001], e[500001];
bool even;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t[i];
        su+=t[i];
    }
    even=(su%2);
    sort(t,t+n);
    ku[0]=0;
    for(long long i=1;i<=n;i++) ku[i]=ku[i-1]+t[i-1];
    e[n]=n;
    for(long long i=n-1;i>=0;i--) e[t[i]]=i;
    for(long long i=n-1;i>=0;i--) if(e[i]==0) e[i]=e[i+1];
    mini=0;
    maxi=n;
    long long j=n, su3=0;
    for(long long i=0;i<=n;i++) {
        long long j=e[n-i-1];
        if(j<i) j=i;
        long long su3=su-ku[j]-(n-j)*(n-i-1);
        mi=su3-su2;
        if(mi>mini) mini=mi;
        j=e[n-i];
        if(j<i) j=i;
        su3=su-ku[j]-(n-j+1)*(n-i);
        ma=su2-su3;
        if(ma<maxi) maxi=ma;
        if(i<n) su2+=t[i];
    }

    bool volt=false;
    for(long long i=mini; i<=maxi; i++) {
        if(i%2==even) {
            cout << i << " ";
            volt=true;
        }
    }
    if(!volt) cout << "-1";
    cout <<  endl;
    return 0;
}