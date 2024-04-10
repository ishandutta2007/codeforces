#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    int n=a.size();
    int d=0;
    for(int i=0;i<n;++i)
        if(a[i]!=b[i])
            ++d;
    if(d%2==1)
        puts("impossible");
    else{
        string w=a;
        d/=2;
        int i=0;
        while(d>0){
            if(b[i]!=a[i]){
                w[i]=b[i];
                --d;
            }
            ++i;
        }
        cout << w;
    }
    return 0;
}