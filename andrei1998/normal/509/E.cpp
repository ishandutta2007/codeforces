#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int n;
char sir[500005];
bool adev[500005];

double sum[500005];

int main()
{
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=500002;i++)
        sum[i]=sum[i-1]+(1.0/i);

    cin.get(sir+1,500005);
    n=strlen(sir+1);

    for(int i=1;i<=n;i++)
        if(sir[i]=='I' || sir[i]=='E' || sir[i]=='A' || sir[i]=='O' || sir[i]=='U' || sir[i]=='Y')
            adev[i]=1;

    double pondere=sum[n];
    double ans=0;

    for(int i=1;i<=n;i++) {
        if(adev[i])
            ans+=pondere;

        pondere-=(sum[n]-sum[n-i]);
        pondere+=(sum[n]-sum[i]);
    }

    cout<<fixed<<setprecision(12)<<ans<<'\n';
    return 0;
}