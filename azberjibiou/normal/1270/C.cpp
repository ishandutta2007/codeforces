#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int T;
long long A[102020];
int main()
{
    gibon
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
            cin >> A[i];
        long long sum=0, xoar=0;
        for(int i=0;i<N;i++)
            sum+=A[i];
        for(int i=0;i<N;i++)
            xoar=xoar^A[i];
        if(2*xoar==sum)
        {
            cout << 0 << '\n' << '\n';
            continue;
        }
        long long a, b, c;
        if(sum%2==1)
        {
            a=10000000000000001;
        }
        else
        {
            a=10000000000000000;
        }
        sum+=a;
        xoar=xoar^a;
        b=xoar-sum/2;
        c=b;
        cout << 3 << '\n';
        cout << a << " " << b << " " << c << '\n';
    }
}