#include <bits/stdc++.h>

using namespace std;

int POWER (int x, int y, int z){
    int pas = 1, p = x;
    while (y){
        if ((y & 1))
            pas = pas * p % z;
        y /= 2;
        p = p * p % z;
    }
    return pas;
}

const int N = 300005;
long long n, m, a[N];
long long p;
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        p += a[i] - a[1];
    if (p >= m){
        cout<<a[1]<<endl;
        return 0;
    }
    m -= p;
    if (a[1] * n < m){
        cout<<-1<<endl;
        return 0;
    }
    cout<<a[1] - (m + n - 1) / n<<endl;
    return 0;
}