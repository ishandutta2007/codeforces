#include <bits/stdc++.h>

using namespace std;

int n, ki, r=0;

int main()
{
    cin >> n;
    while((r+1)*(r+1)<=n) r++;
    for(int i=r;i<n+r;i+=r) {
        for(int j=i;j>i-r;j--) {
            if(j<=n) cout << j << " ";
        }
    }
    cout << endl;
    return 0;
}