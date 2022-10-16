#include <bits/stdc++.h>
 
using namespace std;
 
bool check(long long n,long long mid) {
    long long tot = 0, tempN = n;
    while(n) {
        long long eat = min(mid,n);
        n -= eat;
        n -= n/10;
        tot+=eat;
    }
    return tot*2>=tempN;
}
 
int main()
{
    long long n;
    cin>>n;
    long long left = 1, right = n, ans= 1;
    while(left<=right) {
        long long mid = (left+right)/2;
        if(check(n,mid)) {
            ans = mid, right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout<<ans;
    return 0;
}