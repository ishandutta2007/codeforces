#include <bits/stdc++.h>

using namespace std;

int main() 
{
int n, k;
cin>>n>>k;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
int result = 0;
bool check;
for (int i = 0; i<n; i++)
{
    cin>>check;
    if (check) {result+=a[i]; a[i] = 0;}
}

int maxx = 0;
int cursum = 0;
for (int i = 0; i<k; i++) cursum+=a[i];
maxx = cursum;
for (int i = k; i<n; i++)
{
    
    cursum+=a[i];
    cursum-=a[i-k];
    maxx = max(maxx, cursum);
}

cout<<maxx+result;

}