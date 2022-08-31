#include <bits/stdc++.h>
using namespace std;
int answ = 0;
int tmp = 1;
int counter = 0;
int kk[10000];
bool k[10000];
int n;
void load(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        k[i] = true;
        cin >> kk[i];
    }
}
void solve(){
    while (answ < n){
        if (tmp == 1){
            for (int i = 1; i <= n; i++){
                if (k[i] && (answ >= kk[i])){
                    k[i] = false;
                    answ++;
                }
            }
            counter++;
            tmp = 0;
        }
        else {
            for (int i = n; i >= 1; i--){
                if (k[i] && (answ >= kk[i])){
                    k[i] = false;
                    answ++;
                }
            }
            tmp = 1;
            counter++;
            }
    }
    counter -= 1;
    cout << counter;
}
int main()
{
    load();
    solve();
    return 0;
}