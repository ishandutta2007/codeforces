#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        long long N; cin >> N;
        long long b = 1;
        while(N%2 == 0)
        {
            N /= 2;
            b *= 2;
        }
        long long a = (N-1) / 2;
        if(a == 0) cout << -1 << endl;
        else if(a >= b) cout << 2*b << endl;
        else cout << 2*a+1 << endl;
    }
}