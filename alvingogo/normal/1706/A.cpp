#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s(m,'B');
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            a--;
            a=min(a,m-1-a);
            if(s[a]=='A'){
                s[m-1-a]='A';
            }
            else{
                s[a]='A'; 
            }
        }
        cout << s << "\n";
    }
    return 0;
}