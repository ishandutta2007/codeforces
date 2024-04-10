#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
	AquA;
    int n;
    cin >> n;
    if(n<=2){
        cout << "1\n1 1\n";
        return 0;
    }
    int k=(2*n-2)/3+1;
    cout << k << "\n";
    int l=2*(n-k)-1,f=k-l+1;
    for(int p=1;p<f;p++){
        cout << p << " " << p << "\n";
    }
    for(int i=0,j=0,p=f;p<=k;p++,i=(i+2)%l,j++){
        cout << i+f << " " << j+f << "\n";
    }
	return 0;
}