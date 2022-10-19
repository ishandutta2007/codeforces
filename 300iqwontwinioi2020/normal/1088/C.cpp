
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;


int n, a[N];
vector < int > v1, v2, v3;

int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    cout<<n + 1<<endl;
    cout<<1<<" "<<n<<" "<<n * 10<<endl;
    for (int i = 1; i <= n; i++)
        cout<<2<<" "<<i<<" "<<a[i] + n * 10 - i<<endl;
    return 0;
}