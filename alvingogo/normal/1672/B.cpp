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
        int flag=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B'){
                ans--;
            }
            else{
                ans++;
            }
            if(ans<0){
                flag=1;
                break;
            }
        }
        if(flag==0 && s[s.length()-1]=='B'){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
	return 0;
}