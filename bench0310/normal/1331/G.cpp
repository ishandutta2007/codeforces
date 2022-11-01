#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v(11);
    for(int i=0;i<11;i++) cin >> v[i];
    reverse(v.begin(),v.end());
    for(int x:v)
    {
        double a=sqrt((double)abs(x));
        double b=x*x*x*5;
        double r=a+b;
        cout << "f(" << x << ") = ";
        if(r<=400) cout << fixed << setprecision(2) << r << endl;
        else cout << "MAGNA NIMIS!" << endl;
    }
    return 0;
}