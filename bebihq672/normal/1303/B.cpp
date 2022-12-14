#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
	cin>>T;
	while(T--)
    {
        long long n, g, b;
        cin >> n >> g >> b;
        cout<<max(n, (n - 1)/2/g*(g+b)+(n-1)/2%g+1)<<'\n';
    }
    return 0;
}