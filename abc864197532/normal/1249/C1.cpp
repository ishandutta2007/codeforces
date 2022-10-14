#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

lli mpow (int a,int b) {
    lli ans=1;
    fop (i,0,b) ans*=a;
    return ans;
}

void find (vector <int> &nums,int n) {
    nums[n]=0;
    n++;
    while (n<nums.size()) {
        if (nums[n]==1 or nums[n]==2) {
            nums[n]=0;
        } else {
            nums[n]=1;
            break;
        }
        n++;
    }
    if (n==nums.size()) nums.pb(1);
}
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector <int> nums;
        while (n) {
            nums.pb(n%3);
            n/=3;
        }
        bool is=false;
        fop (i,nums.size(),0) {
            if (is) {
                nums[i]=0;
                continue;
            } if (nums[i]==2) {
                find(nums,i);
                is=true;
            }
        }
        
        
        lli ans=0;
        fop (i,0,nums.size()) {
            ans+=nums[i]*mpow(3,i);
        }
        cout << ans << endl;
    }
}