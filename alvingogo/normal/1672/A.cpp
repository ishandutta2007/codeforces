#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

int main(){
	AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a,sum=0;
        for(int i=0;i<n;i++){
            cin >> a;
            a--;
            sum+=a;
        }
        if(sum%2){
            cout << "errorgorn\n";
        }
        else{
            cout << "maomao90\n";
        }
    }
	return 0;
}