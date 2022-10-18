#include <bits/stdc++.h>

using namespace std;

main()
{
    double m,n;
    cin>>m>>n;
    double t=0;
    for(double i=1;i<=m;i++)
        t+=i*pow(i/m,n)*(1-pow((i-1)/i,n));
    cout<<fixed<<setprecision(9)<<t<<endl;
}