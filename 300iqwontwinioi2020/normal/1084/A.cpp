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
int n, a;
int ans;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a;
        ans += a * 4 * (i - 1);
    }
    cout<<ans<<endl;
    return 0;
}