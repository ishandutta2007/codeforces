#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n=1;
    cin>>n;

    int a,b,c;
    int ans=0;

    for(a=1;a<=n;a++)
        for(b=a;b<=n;b++){
            c=sqrt(a*a+b*b);
            if(c*c==a*a+b*b && c<=n)
                ans++;
        }

    cout<<ans<<endl;
    return 0;
}