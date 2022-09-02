#include <bits/stdc++.h>
using namespace std;

int main()
{
int n, k;
cin>>n>>k;
int a[n];
for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}
int answer[n];

answer[0] =min(n, k+1);
for (int i = 1; i<n; i++)
{
    if (a[i]==-1) answer[i] = 1 + min(i, k) + min(n-1-i, k);
    else 
    {
        int t = min(a[i]+k, n-1);
        int t1 = min(i+k, n-1);
        int t2 = max(i-k, 0);
        t2 = max(t2, t+1);
        answer[i] = answer[a[i]] + t1+1-t2;
    }
}

for (int i = 0; i<n; i++) cout<<answer[i]<<' ';

}