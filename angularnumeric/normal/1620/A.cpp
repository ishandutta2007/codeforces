#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n = s.length();
        int a[n];
        for(int i=0; i<n; i++) {
            if(s[i] == 'E') a[i] = 1;
            else a[i] = 0;
        }
        int flag = 1;
        for(int i=0; i<n; i++) {
            if(a[i] == 0) {
                int c = 0;
                for(int j=1; j<n; j++) {
                    if(a[(i+j)%n] == 1) c++;
                    else break;
                }
                if(c == n-1) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}