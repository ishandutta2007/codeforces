#include <bits/stdc++.h>

using namespace std;
bool v[60], f[60];
int n, a, b;
int main()
{
    cin >> n;
    for(int i=0;i<n*n;i++) {
        cin >> a >> b;
        if(!v[a]&&!f[b]) {
            cout << i+1 << " ";
            v[a]=true;
            f[b]=true;
        }
    }
    cout << endl;
    return 0;
}