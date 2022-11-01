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
    long long res=a[n-1];
    long long num=a[n-1]-1;
    for(int i=n-2;i>=0;i--)
    {
        res+=min(num,a[i]);
        num=max(min(num,a[i])-1,0ll);
    }
    cout << res << endl;
    return 0;
}