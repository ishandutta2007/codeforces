#include <bits/stdc++.h>

using namespace std;

int N, K;
string s, t;
long long ans = 0;

int main(){
    cin >> N >> K >> s >> t;
    long long c = 1;
    long long numfree = 0;
    bool together = 1;
    for(int i = 0; i<N; i++){
        numfree *= 2;
        if(together && s[i] == t[i]){
            //ans += 1;
        }
        else if(together && s[i] != t[i]){
            together = 0;
            c++;
        }
        else{
            numfree += (s[i] == 'a') + (t[i] == 'b');
        }
        numfree = min(1LL*K, numfree);
        //c += numfree;
        c = min(1LL*K, c);
        ans += min(c + numfree, 1LL*K);
        //cout << i << " " << c << " " << numfree << " " << ans << endl;
    }
    cout << ans << endl;
}