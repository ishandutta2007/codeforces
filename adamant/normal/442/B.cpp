#include <bits/stdc++.h>

using namespace std;

#define TASK "test"
#define double long double

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<double> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    sort(begin(x),end(x));
    reverse(begin(x),end(x));
    vector<double> DP_best(n,0);
    vector<double> DP_mul(n,0);
    for(int i=0;i<n;i++)
    {
        DP_best[i]=x[i];
        DP_mul[i]=1-x[i];
    }
    for(int i=1;i<n;i++)
    {
        if(DP_best[i-1]>DP_best[i] || (DP_best[i-1]==DP_best[i] && DP_mul[i-1]>DP_mul[i]))
        {
            DP_best[i]=DP_best[i-1];
            DP_mul[i]=DP_mul[i-1];
        }
        for(int j=i-1;j<i;j++)
        {
            double t=x[i]*DP_mul[j]+(1-x[i])*DP_best[j];
            if(t>DP_best[i] || (t==DP_best[i] && DP_mul[j]*(1-x[i])>DP_mul[i]))
            {
                DP_best[i]=t;
                DP_mul[i]=DP_mul[j]*(1-x[i]);
            }
        }
    }
    cout<<fixed<<setprecision(12)<<DP_best[n-1]<<endl;
}