#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long long res=0,num=0;
    for(int i=0;i<n;i++)
    {
        long long b=min(a[i]/2,num);
        res+=b;
        num-=b;
        a[i]-=(b*2);
        res+=(a[i]/3);
        a[i]%=3;
        num+=a[i];
    }
    cout << res << endl;
    return 0;
}