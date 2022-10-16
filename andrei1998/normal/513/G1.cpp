#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
int p[105];

inline int invs () {
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=(p[i]>p[j]);

    return ans;
}

int vars=0;
long long int backtr (int k) {
    if(!k) {
        vars++;
        return invs();
    }

    long long int s=0;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) {
            reverse(p+i,p+j+1);
            s+=backtr(k-1);
            reverse(p+i,p+j+1);
        }

    return s;
}

int main()
{
    int k=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>p[i];

    long long int aux=backtr(k);

    cout<<fixed<<setprecision(12)<<((long double)aux)/vars<<'\n';
    return 0;
}