#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
string s, s1;

int main(){
   int n, i, n1, ans, cnt, j;
    cin >> s;
    cin >> s1;
    n = s.length();
    n1 = s1.length();
    ans = max(n1, n);

    for (i = -n1 + 1; i < n; i++){
        cnt = 0;
        for (j = 0; j < n1 ; j++){
            if (i + j < 0 || i + j >= n){
                cnt++;
                continue;
            }
            if (s1[j] != s[i + j])
                cnt++;
        }
        ans = min(cnt, ans);
    }

    cout << ans;



    return 0;
}