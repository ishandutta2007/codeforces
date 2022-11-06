#include <iostream>
#include <iomanip>

using namespace std;

long n,m,i;
double act,last,ans;

double power(double x,long p){
    double ans=1;
    while(p){
        if(p&1) ans *= x;
        x *= x;
        p >>= 1;
    }
    return ans;
}

int main()
{
    cin >> m >> n;

    last = 0; ans = 0;
    for(i=1;i<=m;i++){
        act = power((1.00*i)/m,n);
        ans += (act - last)*1.00*i;
        last = act;
    }

    cout << setprecision(5) << ans;

    return 0;
}