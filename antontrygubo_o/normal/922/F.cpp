#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int dividedby[n+1] = {0};

    long long countall = 0;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 2*i; j<=n; j+=i) {dividedby[j]++; countall++;}
    }
    if (countall<k) {cout<<"No"; return 0;}
    cout<<"Yes"<<endl;
    //cout<<countall<<endl;
    //for (int i = 1; i<=n; i++) cout<<i<<' '<<dividedby[i]<<endl;
    while (countall-dividedby[n]>=k) {countall-=dividedby[n]; n--;}
    bool take[n+1];
    for (int i = 1; i<=n; i++) take[i] = true;
    int much = countall-k;
   // cout<<n<<' '<<countall<<' '<<much<<endl;
    int counttake = n;
    
    while (much!=0)
    {
        int idx = (n+2)/2;
        while ((!take[idx])||(dividedby[idx]>much)) idx++;
        int idxmaxx = idx;
        for (int i = idx; i<=n; i++) if ((take[i])&&(dividedby[i]>dividedby[idxmaxx])&&(dividedby[i]<=much)) idxmaxx = i;
        much-=dividedby[idxmaxx];
        take[idxmaxx] = false;
        counttake--;
    }
cout<<counttake<<endl;
for (int i = 1; i<=n; i++) if (take[i]) cout<<i<<' ';
}