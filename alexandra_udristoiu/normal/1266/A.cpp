#include<iostream>
#include<cstring>
using namespace std;
int n, i, nr, ok, sum, m, j;
char s[105];
int main(){
    cin>> n;
    for(; n; n--){
        cin>> s + 1;
        m = strlen(s + 1);
        sum = ok = nr = 0;
        if(m == 1 && s[1] == '0'){
            cout<<"red\n";
            continue;
        }
        for(j = 1; j <= m; j++){
            s[j] -= '0';
            sum += s[j];
            if(s[j] == 0){
                ok = 1;
            }
            if(s[j] % 2 == 0){
                nr++;
            }
        }
        if(ok == 1 && nr >= 2 && sum % 3 == 0){
            cout<<"red\n";
        }
        else{
            cout<<"cyan\n";
        }
    }
}