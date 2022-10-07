#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
char s[1000002];
long long b[1000002];

int main(){
    long long sum = 0, uk, kol;
    int k, n, i;
    cin >> k;
    scanf("%s", s);
    n = strlen(s);
    if (k == 0){
        sum = 0;
        kol = 0;
        for (i = 0; i < n; i++)
            if (s[i] == '0'){
                kol++;
            }
            else{
                sum += kol * (kol + 1) / 2;
                kol = 0;
            }
        sum += kol * (kol + 1) / 2;
        cout << sum;
        return 0;
    }
    uk = 1;
    b[0] = -1;
    for (i = 0; i < n; i++){
        if (s[i] == '1'){
            b[uk++] = i;
        }
    }
    b[uk] = n;
    for (i = 1; i < uk - k + 1; i++){
        sum = sum + (b[i] - b[i - 1]) * (b[i + k] - b[i + k - 1]); 
    }
    cout << sum;

    return 0;
}