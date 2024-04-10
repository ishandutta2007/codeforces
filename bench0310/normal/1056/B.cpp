#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n,m;
    cin >> n >> m;
    long long cnt=0;
    for(int o=1;o<=min(m,n);o++)
    {
        for(int i=1;i<=min(m,n);i++)
        {
            if((((o*o)%m)+((i*i)%m))%m==0)
            {
                cnt+=max(((n-i+m)/m)*((n-o+m)/m),(long long)0);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}