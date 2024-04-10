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
        string s;
        cin >> s;
        if(s.length()==2){
            cout << s[1] << "\n";
        }
        else{
            char maxx='9'+1;
            for(auto h:s){
                maxx=min(maxx,h);
            }
            cout << maxx << "\n";
        }
    }
	return 0;
}