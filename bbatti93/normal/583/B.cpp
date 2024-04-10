#include <bits/stdc++.h>

using namespace std;

int n, ki, t[1001], most=0;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t[i];
    }
    while(true) {
        for(int i=0;i<n;i++) {
            if(most>=t[i]) {
                most++;
                t[i]=10000;
            }
        }
        if(most==n) break;
        ki++;
        for(int i=n-1;i>=0;i--) {
            if(most>=t[i]) {
                most++;
                t[i]=10000;
            }
        }
        if(most==n) break;
        ki++;
    }
    cout << ki << endl;
    return 0;
}