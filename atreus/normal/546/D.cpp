#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e6 + 5000;
bool prime[maxn];
int divisor[maxn];
long long div1[maxn];


void f(){
    prime[1] = 0;
    for (int i = 2; i < maxn; i++){
        if (prime[i] == 0){
            divisor[i] = i;
            for (int j = i + i; j < maxn; j += i){
                prime[j] = 1;
                divisor[j] = i;
            }
        }
    }
    div1[1] = 0;
    for (int i = 2; i < maxn; i++)
        div1[i] = div1[i / divisor[i]] + 1;
    for (int i = 2; i < maxn; i++)
        div1[i] += div1[i - 1];
}

int main (){
    ios_base::sync_with_stdio(false);
    f();
    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        cout << div1[a] - div1[b] << endl;
    }
}