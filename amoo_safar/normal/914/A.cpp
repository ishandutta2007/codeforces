#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
inline int approx_sqrt(int m)
{
    return static_cast<int>(ceil(sqrt(static_cast<double>(m))));
}
int main(){
    ll n,a,s;
    cin >> n;
    ll ma = -10000000;
    for(int i =0;i<n;i++){
        cin >> a;
        if(a<0){
            ma = max(ma,a);
            continue;
        }
        s = approx_sqrt(a);
        if(((ll)s*s) != a) ma = max(ma,a);
    }
    cout << ma;
    return 0;
}