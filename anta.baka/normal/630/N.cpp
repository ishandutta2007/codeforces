#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout.precision(6);
    if(b==0)
        cout<<fixed<<sqrt(-1.0*c/a)<<"\n"<<fixed<<-sqrt(-1.0*c/a);
    else if(c==0)
        cout<<fixed<<max(0.0,-1.0*b/a)<<"\n"<<fixed<<min(0.0,-1.0*b/a);
    else {
        double d=b*b-4*a*c;
        if(abs(d)<0.000001)
            cout<<fixed<<sqrt(1.0*c/a)<<"\n"<<fixed<<-sqrt(1.0*c/a);
        else
            cout<<fixed<<max((-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a))<<"\n"<<fixed<<min((-b-sqrt(d))/(2*a),(-b+sqrt(d))/(2*a));
    }
    return 0;
}