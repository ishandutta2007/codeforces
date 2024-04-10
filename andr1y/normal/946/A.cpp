#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int sum1=0, sum2=0;
    for(int i=0;i<n;i++)if(a[i]>=0)sum1+=a[i];else sum2+=a[i];
    cout << sum1-sum2;
}